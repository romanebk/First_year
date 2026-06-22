/*
** EPITECH PROJECT, 2024
** lkjhg
** File description:
** jhgf
*/

#include "my.h"

void usage2(void)
{
    printf(" -e, --scale-task-mem =SCALE     ");
    printf("set mem with: k,m,g,t,p for SCALE\n");
    printf(" -H, --threads-show              ");
    printf("show tasks plus all their threads\n");
    printf(" -i, --idle-toggle               ");
    printf("reverse last remembered 'i' state\n");
    printf(" -n, --iterations =NUMBER        ");
    printf("exit on maximum iterations NUMBER\n");
    printf(" -O, --list-fields               ");
    printf("output all field names, then exit\n");
    printf(" -o, --sort-override =FIELD      ");
    printf("force sorting on this named FIELD\n");
    printf(" -p, --pid =PIDLIST              ");
    printf("monitor only the tasks in PIDLIST\n");
    printf(" -S, --accum-time-toggle         ");
    printf("reverse last remembered 'S' state\n");
    printf(" -s, --secure-mode               ");
}

void usage3(void)
{
    printf("run with secure mode restrictions\n");
    printf(" -U, --filter-any-user =USER     ");
    printf("show only processes owned by USER\n");
    printf(" -u, --filter-only-euser =USER   ");
    printf("show only processes owned by USER\n");
    printf(" -w, --width [=COLUMNS]          ");
    printf("change print width [,use COLUMNS]\n");
    printf(" -1, --single-cpu-toggle         ");
    printf("reverse last remembered '1' state\n\n");
    printf(" -h, --help                      ");
    printf("display this help text, then exit\n");
    printf("-V, --version                   ");
    printf("output version information & exit\n\n");
    printf("For more details see top(1).\n");
}

int usage(int argc, char **argv)
{
    if (argc == 2) {
        if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
            printf("Usage:\n   top [options]\n\n");
            printf("Options:\n -b, --batch-mode                ");
            printf("run in non-interactive batch mode\n");
            printf(" -c, --cmdline-toggle            ");
            printf("reverse last remembered 'c' state\n");
            printf(" -d, --delay =SECS [.TENTHS]     ");
            printf("iterative delay as SECS [.TENTHS]\n");
            printf(" -E, --scale-summary-mem =SCALE  ");
            printf("set mem as: k,m,g,t,p,e for SCALE\n");
            usage2();
            usage3();
        }
    } else {
        exit(84);
    }
    return 0;
}
