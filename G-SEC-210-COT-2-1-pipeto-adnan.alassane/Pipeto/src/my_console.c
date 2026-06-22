/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** my_console
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dlfcn.h>
#include <sys/types.h>
#include "pipeto.h"
#include "ansi-colors.h"
#include "utils.h"
#include "history.h"

bool IS_ADMIN = false;

const char *command_strings[] = {
    "init_reactor",
    "check_reactor_status",
    "activate_emergency_protocols",
    "simulate_meltdown",
    "check_cooling_pressure",
    "send_status_report",
    "monitor_radiation_levels",
    "set_reactor_power",
    "run_diagnostic",
    "enable_remote_access",
    "quit",
    "help",
    "load_fuel_rods",
    "log_system_event",
    "unlock_secret_mode",
    "load_config",
    "history",
    "configure_cooling_system",
    "trigger_emergency_shutdown",
};

static void initialize_commands(void (*f[COMMAND_COUNT])(char *input))
{
    f[INIT_REACTOR] = init_reactor;
    f[CHECK_REACTOR_STATUS] = check_reactor_status;
    f[ACTIVATE_EMERGENCY_PROTOCOLS] = activate_emergency_protocols;
    f[SIMULATE_MELTDOWN] = simulate_meltdown;
    f[CHECK_COOLING_PRESSURE] = check_cooling_pressure;
    f[SEND_STATUS_REPORT] = send_status_report;
    f[MONITOR_RADIATION_LEVELS] = monitor_radiation_levels;
    f[SET_REACTOR_POWER] = set_reactor_power;
    f[RUN_DIAGNOSTIC] = run_diagnostic;
    f[ENABLE_REMOTE_ACCESS] = enable_remote_access;
    f[QUIT] = quit;
    f[HELP] = help;
    f[LOAD_FUEL_RODS] = load_fuel_rods;
    f[LOG_SYSTEM_EVENT] = log_system_event;
    f[UNLOCK_SECRET_MODE] = unlock_secret_mode;
    f[LOAD_CONFIG] = load_config;
    f[HISTORY] = show_history;
    f[CONFIGURE_COOLING_SYSTEM] = configure_cooling_system;
    f[TRIGGER_EMERGENCY_SHUTDOWN] = trigger_emergency_shutdown;
}
const char *command_strings_lib[] = {
    "init_steam_turbine",
    "read_turbine_config",
    "turbine_remote_access",
    "turbine_temperature",
    "run_turbine",
};

static void check_pepito_lib(char *input)
{
    void *dlh = dlopen("libpepito.so", RTLD_LAZY);
    void (*fnc)(void) = dlsym(dlh, input);

    if (!dlh) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }
    if (!fnc) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }
    fnc();
}

static bool try_execute_internal_command(char *line, void (*f[])(char *))
{
    for (int i = 0; i < COMMAND_COUNT; i++) {
        if (strcmp(line, command_strings[i]) == 0) {
            f[i](line);
            return true;
        }
    }
    return false;
}

bool try_execute_history(char *line, void (*f[])(char *))
{
    int index = 0;

    if (line[0] != '!')
        return false;
    index = atoi(line + 1);
    if (index <= 0 || index > history_count_get()) {
        printf("Invalid history index\n");
        return true;
    }
    const char * cmd = history_get(index - 1);
    if (cmd) {
        printf("%s\n", cmd);
        process_command((char *)cmd, f);
    }
    return true;
}

static bool try_execute_lib_command(char *line)
{
    for (int i = 0; i < COMMAND_COUNT_LIB; i++) {
        if (strcmp(line, command_strings_lib[i]) == 0) {
            check_pepito_lib(line);
            return true;
        }
    }
    return false;
}

void process_command(char *line, void (*f[COMMAND_COUNT])(char *input))
{
    if (try_execute_internal_command(line, f))
        return;
    if (try_execute_lib_command(line))
        return;
    if (try_execute_history(line, f))
        return;
    if (strlen(line) > 0)
        printf("Unknown command: %s\n", line);
}


void show_history(char *input)
{
    (void)input;
    history_show();
}

int my_console(void)
{
    char *line = NULL;
    size_t len = 0;
    void (*f[COMMAND_COUNT])(char *input);

    initialize_commands(f);
    history_init();
    load_pipetorc();
    while (1) {
        write_color(1, BHRED, "pipeto");
        if (getline(&line, &len, stdin) == -1)
            break;
        line[strcspn(line, "\n")] = '\0';
        if (strlen(line) == 0)
            continue;
        history_add(line);
        process_command(line, f);
    }
    history_free();
    free(line);
    return 0;
}
