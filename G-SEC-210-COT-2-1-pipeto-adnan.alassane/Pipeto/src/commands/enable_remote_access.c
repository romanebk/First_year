/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** enable_remote_access
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

void perform_network_call(const char *url)
{
    printf("Performing network call to: %s\n", url);
    for (volatile int i = 0; i < 100000000; i++);
    sleep(5);
    printf("Network call to %s completed.\n", url);
}

void log_access_attempt(const char *status)
{
    time_t now = time(NULL);
    char *timestamp = ctime(&now);

    timestamp[strlen(timestamp) - 1] = '\0';
    printf("[%s] Remote access status: %s\n", timestamp, status);
}

void enable_remote_access_cut(int enabled, char *dummy_urls)
{
    printf("Enabling remote access...\n");
    perform_network_call(dummy_urls);
    log_access_attempt("ENABLED");
    enabled = 1;
    printf("Remote access successfully enabled.\n\n");
    printf("Performing status check...\n");
    perform_network_call(dummy_urls);
}

void enable_remote_access(void)
{
    int enabled = 0;
    const char *dummy_urls[] = {
        "http://example.com/api/enable",
        "http://example.com/api/disable",
        "http://example.com/api/status"
    };

    printf("Initializing remote access procedure...\n\n");
    if (enabled == 0) {
        enable_remote_access_cut(enabled, dummy_urls[0]);
        printf("Status check complete.\n\n");
    } else {
        printf("Disabling remote access...\n");
        perform_network_call(dummy_urls[1]);
        log_access_attempt("DISABLED");
        enabled = 0;
        printf("Remote access successfully disabled.\n\n");
    }
}
