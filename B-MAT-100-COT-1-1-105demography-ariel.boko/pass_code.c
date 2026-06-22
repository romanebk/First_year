/*
** EPITECH PROJECT, 2024
** pass_function
** File description:
** pass
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

int pass_code(int argc, char **argv, char *str)
{
    char *contain = file("105demography_data.csv");
    char **tab;
    int i = 0;

    if (contain == NULL)
        return 84;
    tab = my_str_to_word_array(contain);
    if (tab == NULL) {
        free(contain);
        return 84;
    }
    while (tab[i] != NULL) {
      if (strcmp(tab[i], str) == 0) {
	printf("%s, ", tab[i - 1]);
        //strcpy(tab[i - 1], dest);
        //printf("%s \n", dest);
      } /*else if (strcmp(tab[i], str) != 0) {
	return 84;
      }*/
        i++;
    }
    return 0;
}
/*
int main(int argc, char **argv)
{
  for (int i = 0; i < argc; i++) {
    printf("%d\n", check(argv[i]));
    return 0;
  }
}
*/
