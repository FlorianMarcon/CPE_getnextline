/*
** EPITECH PROJECT, 2017
** get_next_line
** File description:
** get_next_line
*/

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

int	my_strlen(char const *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (*str != '\0') {
		str++;
		i++;
	}
	return (i);
}
char	*my_strcat(char *dest, char const *src)
{
	int len = my_strlen(dest) + my_strlen(src) + 1;
	char *resultat = NULL;
	int i = 0;

	if ((resultat = malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	len = 0;
	if (dest != NULL) {
		while (dest[len] != '\0') {
			resultat[len] = dest[len];
			len++;
		}
	}
	while (src[i] != '\0' && src != NULL) {
		resultat[len] = src[i];
		len++;
		i++;
	}
	resultat[len] = '\0';
	return (resultat);
}
int	is_end_line(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0') {
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*copy_extra_char(char *str)
{
	int i = 0;
	char *new = NULL;

	while (str[i] != '\n')
		i++;
	str[i] = '\0';
	str = &str[i + 1];
	if (my_strlen(str) != 0) {
		if ((new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
			return (NULL);
		i = 0;
		while (str[i] != '\0') {
			new[i] = str[i];
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
char	*get_next_line(int fd)
{
	char *tmp = NULL;
	int var = 0;
	static char *buffer = NULL;

	while (is_end_line(buffer) != 1) {
		if ((tmp = malloc(sizeof(char)* (READ_SIZE + 1))) == NULL)
			return (NULL);
		var = read(fd, tmp, READ_SIZE);
		if (var <= 0)
			return (NULL);
		tmp[var] = '\0';
		buffer = my_strcat(buffer, tmp);
		free(tmp);
	}
	tmp = buffer;
	buffer = copy_extra_char(tmp);
	return (tmp);
}
