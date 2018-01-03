/*
** EPITECH PROJECT, 2017
** main
** File description:
** a supprilmer
*/

#include <stdio.h>
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	char *tmp = get_next_line(fd);

	if (ac == 2) {
		while (tmp) {
			my_putstr(tmp);
			my_putchar('\n');
			free(tmp);
			tmp = get_next_line(fd);
		}
	}
}
