/*
** EPITECH PROJECT, 2024
** dfghjk
** File description:
** hgfd
*/
#include "my.h"

void verify_pwd(int ac, char **av)
{
    char *pwd = recup();
    char enter[2000];
    char *retour_crypt = NULL;
    int a = 1;

    if (strcmp(getlogin(), "root") == 0)
        my_exec(av[1], &av[1]);
    for (int i = 0; i <= 2; i++) {
        printf("[sudo] password for %s: ", getlogin());
        system("stty -echo");
        scanf("%1999s", enter);
        retour_crypt = crypt(enter, pwd);
        if (strcmp(retour_crypt, pwd) == 0) {
            my_exec(av[1], &av[1]);
            break;
        } else {
            printf("Sorry, try again.\n");
        }
    }
    return;
}
