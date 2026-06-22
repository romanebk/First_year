/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** send_status_report
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void encode_block(unsigned char in[3], char out[4], int len)
{
    char table[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefgh";
    unsigned char temp[4];

    strcat(table, "ijklmnopqrstuvwxyz0123456789+/");
    temp[0] = (in[0] & 0xFC) >> 2;
    temp[1] = ((in[0] & 0x03) << 4) | ((in[1] & 0xF0) >> 4);
    temp[2] = ((in[1] & 0x0F) << 2) | ((in[2] & 0xC0) >> 6);
    temp[3] = in[2] & 0x3F;
    for (int i = 0; i < 4; i++)
        out[i] = (i < len + 1) ? table[temp[i]] : '=';
}

int process_input(const char *input, char *output)
{
    int i = 0;
    int j = 0;
    unsigned char buffer[3];
    char encoded[4];

    while (*input) {
        buffer[i++] = *(input++);
	if (i == 3) {
            encode_block(buffer, encoded, 3);
            for (int k = 0; k < 4; k++)
                output[j++] = encoded[k];
            i = 0;
        }
    }
    return i ? i : 0;
}

void base64_encode(const char *input, char *output)
{
    int len = strlen(input);
    int remaining = 0;
    unsigned char tail[3] = {0};
    char encoded[4];
    int out_index = 0;

    remaining = process_input(input, output);
    out_index = strlen(output);
    if (remaining > 0) {
        strncpy((char *)tail, input + len - remaining, remaining);
        encode_block(tail, encoded, remaining);
        for (int i = 0; i < 4; i++)
            output[out_index++] = encoded[i];
    }
    output[out_index] = '\0';
}

void create_dir(void)
{
    struct stat st = {0};
    if (stat("Data", &st) == -1) {
        if (mkdir("Data", 0755) != 0) {
            perror("mkdir failed");
            return;
        }
    }
}

void send_status_report(void)
{
    const char *hostname = "localhost";
    const char *ip_address = "127.0.0.1";
    const char *process_info = "Process: pipeto (PID: 1234)";
    FILE *file = NULL;
    char report[256];
    char encoded_report[512];

    create_dir();
    file = fopen("Data/status_report.txt", "w");
    if (!file) {
        printf("Error: Unable to open 'Data/status_report.txt' for writing.\n");
        return;
    }
    snprintf(report, sizeof(report),
    "Hostname: %s\nIP Address: %s\n%s\n",
    hostname, ip_address, process_info);
    base64_encode(report, encoded_report);
    fprintf(file, "Encoded Status Report:\n%s\n", encoded_report);
    fclose(file);
    printf("Status report sent and saved to 'Data/status_report.txt'.\n");
}
