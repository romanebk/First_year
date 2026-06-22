#ifndef LIB_H
    #define LIB_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <string.h>
    #include <time.h>
    #include <stddef.h>
    #include <stdarg.h>
    #include <utmp.h>
    #include <ctype.h>
    #include <ncurses.h>
    #include <curses.h>
    #include <dirent.h>
    #include <sys/types.h>

int my_worldlen(char const *str, char sep);
char **alloc(char const *str, char sep, char **r);
char **str_array(char const *str, char sep);
#endif
