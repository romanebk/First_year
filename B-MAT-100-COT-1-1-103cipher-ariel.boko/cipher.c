/*
** EPITECH PROJECT, 2024
** cipher
** File description:
** criptage
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int usage(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
        printf("USAGE\n    ./103cipher message key flag\n\n\n");
        printf("DESCRIPTION\n");
        printf("    message     a message, made of ASCII characters\n");
        printf("    key         the encryption key, made of ASCII characters\n");
        printf("    flag        0 for the message to be encrypted, 1 to be decrypted\n");
    }
    else {
        exit(84);
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
        usage(argc, argv);
    }
    else {
        return 84;
    }
}
