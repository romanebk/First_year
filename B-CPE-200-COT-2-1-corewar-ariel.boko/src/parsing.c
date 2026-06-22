
/*
** EPITECH PROJECT, 2025
** function
** File description:
** parsing
*/

#include "../include/my.h"

int put_error(char *msg)
{
    write(2, msg, my_strlen(msg));
    return 84;
}

static int get_file_size(char const *file_path)
{
    int fd = open(file_path, O_RDONLY);
    char buff;
    int size = 0;

    if (fd < 0)
        put_error("Error: Can't open file !\n");
    for (; read(fd, &buff, 1); size++);
    return size;
}

int verify_file(char *path, char **buffer)
{
    int size = get_file_size(path);
    int fd = open(path, O_RDONLY);
    char *buff = NULL;

    if (fd < 0) {
        put_error("Error: Can't open file.\n");
        return 84;
    }
    buff = malloc(sizeof(char) * (size + 1));
    if (buff == NULL || !buff)
        return 84;
    buff[size] = '\0';
    if (read(fd, buff, size) != size)
        put_error("Error: Can't read file.\n");
    if (!(buff[0] == 0 && buff[1] == -22 && buff[2] == -125 && buff[3] == -13))
        put_error("Error: Incorrect program_file.\n");
    *buffer = buff;
}

void fill_header(const char *file_name)
{
    header_t *var = malloc(sizeof(header_t));
    FILE *file = fopen(file_name, "rb");

    if (!fread(var, sizeof(header_t), 1, file)
        || file == NULL || var == NULL) {
        free(var);
        fclose(file);
        return;
    }
    var->magic = move_indian(var->magic);
    var->prog_size = move_indian(var->prog_size);
    if (var->magic != COREWAR_EXEC_MAGIC ||
        var->prog_size == 0 || var->prog_size > MEM_SIZE) {
        free(var);
        return;
    }
    var->prog_name[PROG_NAME_LENGTH] = '\0';
    var->comment[COMMENT_LENGTH] = '\0';
}
