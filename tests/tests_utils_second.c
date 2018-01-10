/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "get_next_line.h"

Test(is_end_line, test)
{
	char str[] = "salut comment tu vas?\n\0";
	char str2[] = "il n'y a pas de fin de ligne\0";

	cr_assert_eq(is_end_line(str), 1);
	cr_assert_eq(is_end_line(str2), 0);
}
