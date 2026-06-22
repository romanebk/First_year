/*
** EPITECH PROJECT, 2025
** main_file
** File description:
** file_main
*/

#include "lib.h"

int str_len(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}

void put_str(char *str)
{
    write(1, str, str_len(str));
}

void show_array(char **str)
{
    for (int i = 0; str[i] != NULL; i++) {
	put_str(str[i]);
	put_str("\n");
    }
}

char **read_stdin(void)
{
    char content[10240];
    char **words = NULL;

    read(STDIN_FILENO, content, sizeof(content));
    content[sizeof(content) - 1] = '\0';
    words = str_array(content, '\n');
    return words;
}

int is_tiret(char const *str)
{
    int index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
	if (str[i] == '-')
	    index++;
    }
    return index;
}

int *interval(char const *str, char *dtr)
{
    char **dest = str_array(str, ',');
    char **crazy = NULL;
    int index = 0;
    int dup[10240];
    int value;

    for (int i = 0; dest[i] != NULL; i++) {
	if (is_tiret(dest[i]) == 0) {
	    dup[index] = atoi(dest[i]);
	    index++;
	}
	if (is_tiret(dest[i]) > 0) {
	    crazy = str_array(dest[i], '-');
	    for (int j = 0; crazy[j] != NULL; j++) {
		for (int k = 1; crazy[k] != NULL; k++) {
		    value = atoi(crazy[j]);
		    for (; value <= atoi(crazy[k]); value++) {
			dup[index] = value;
			index++;
		    }
		}
	    }
	}
	if (dest[i][str_len(dest[i]) - 1] == '-') {
	    value = atoi(dest[i]);
	    for (; value < str_len(dtr); value++) {
	    dup[index] = value;
	    index++;
	    }
	}
	    
    }
    int *arr = malloc(sizeof(int) * index);
    for (int i = 0; i < index; i++) {
	arr[i] = dup[i];
    }
    return arr;
}

int main(int av, char **str)
{
    char *dtr = strdup(str[1]);
    char **dest = read_stdin();   
    int *recup = interval(dtr, dest[0]);

    for (; *recup; recup++)
	printf("%d\n", *recup);
}
