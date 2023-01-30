#ifndef GNL_H
#define GNL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#define BUFFER_SIZE 42

char *ft_get_next_line(int fd);
void ft_putstr(char *str);

#endif
