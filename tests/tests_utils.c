/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include "get_next_line.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int fd = -1;

void	open_file(void)
{
	fd = open("data.txt", O_RDONLY);
	cr_redirect_stdout();
}

void	close_file(void)
{
	if (fd != -1)
		close(fd);
}

Test(get_next_line, read_line, .init = open_file, .fini = close_file)
{
	char *expected = "Ceci est un fichier";
	char *got = get_next_line(fd);

	cr_assert_str_eq(expected, got);
	free(got);
	got = get_next_line(fd);
	cr_assert_str_eq(got, "Que j'utilise pour tester mon programme");
	free(got);
	got = get_next_line(fd);
	cr_assert_str_eq(got, "Ce test m'a été donné par le pdf");
	free(got);
	got = get_next_line(fd);
	cr_assert_eq(got, NULL);

}
