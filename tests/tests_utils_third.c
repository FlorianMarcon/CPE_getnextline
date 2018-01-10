/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "get_next_line.h"

Test(copy_extra_char, test)
{
	char str[] = "salut comment \ntu vas ?\0";

	cr_assert_str_eq(copy_extra_char(str), "tu vas ?\0");
}
Test(copy_extra_char, test2)
{
	char str[] = "salut comment \n\0";

	cr_assert_null(copy_extra_char(str));
}
