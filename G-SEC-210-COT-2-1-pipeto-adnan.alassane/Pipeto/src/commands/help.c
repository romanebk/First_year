/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** help
*/

#include <stdio.h>
#include <string.h>
#include "../../include/pipeto.h"

void help_cut(void)
{
    printf("- init_reactor: Initialize the reactor for operation.\n");
    printf("- check_reactor_status: Check the current");
    printf(" status of the reactor.\n");
    printf("- activate_emergency_protocols: Activate ");
    printf("emergency protocols (requires admin).\n");
    printf("- simulate_meltdown: Simulate a reactor ");
    printf("meltdown for testing purposes.\n");
    printf("- check_cooling_pressure: Check the");
    printf(" pressure in the cooling system.\n");
    printf("- send_status_report: Send a status");
    printf(" report to the control center.\n");
    printf("- monitor_radiation_levels: Monitor ");
    printf("radiation levels in the reactor.\n");
    printf("- set_reactor_power: Adjust the ");
    printf("reactor's power output.\n");
    printf("- run_diagnostic: Run a full diagnostic");
    printf(" on the reactor systems.\n");
    printf("- enable_remote_access: Enable or disable");
    printf(" remote access to the reactor.\n");
}

void cut_help(void)
{
    printf("- quit: Exit the console.\n");
    printf("- help: Display this help message.\n");
    printf("- load_fuel_rods: Load fuel rods into");
    printf(" the reactor.\n");
    printf("- log_system_event: Log a system event.\n");
    printf("- history: Display command history.\n");
    printf("- !n: Execute command number n from history.\n");
    printf("- load_config: Load configuration from a file.\n");
    printf("- configure_cooling_system: Configure");
    printf(" the cooling system.\n");
}

void help(void)
{
    help_cut();
    cut_help();
    printf("---- External libraries ----\n");
    printf("- init_steam_turbine: Initialize the turbine.\n");
    printf("- read_turbine_config: Read the turbine configuration.\n");
    printf("- run_turbine: Run the turbine.\n");
    printf("- turbine_temperature: Change the turbine temperature.\n");
    printf("- turbine_remote_access: Remote access to the turbine.\n\n");
    printf("Configuration:\n");
    printf("- .pipetorc: Create this file in your");
    printf(" home directory or current directory\n");
    printf("  to automatically execute commands at startup.\n");
    printf("  Use 'exec <command>' to execute shell commands.\n\n");
}
