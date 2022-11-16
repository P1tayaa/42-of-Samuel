/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:19:44 by sboulain          #+#    #+#             */
/*   Updated: 2022/11/16 14:19:03 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_those(char *char_rd, char *char_rding)
{
	if (char_rd != NULL)
		free(char_rd);
	char_rd = NULL;
	if (char_rding != NULL)
		free(char_rding);
	char_rding = NULL;
	return (NULL);
}

char	*copy_line(const char *s, int i)
{
	char	*dupstr;
	int		did_new_line;

	if (!s)
		return (NULL);
	did_new_line = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		did_new_line = 1;
	if (i == 0 && !did_new_line)
		return (NULL);
	dupstr = (char *)malloc((i + did_new_line + 1) * sizeof(char));
	if (!dupstr)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		dupstr[i] = s[i];
		i++;
	}
	if (did_new_line)
		dupstr[i] = '\n';
	dupstr[i + did_new_line] = '\0';
	return (dupstr);
}

char	*find_new_line(
		char *buffer, int number_line, size_t nb_char_rd, int *finish)
{
	size_t	i;
	int		current_number_line;
	char	*start_current_line_pointer;

	i = 0;
	current_number_line = 0;
	start_current_line_pointer = buffer;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			if (current_number_line == number_line)
				return (start_current_line_pointer);
			current_number_line++;
			start_current_line_pointer = &buffer[i + 1];
		}
		i++;
	}
	if (buffer[i] == '\0' && nb_char_rd == 0 && *finish != 1)
	{
		*finish = 1;
		return (start_current_line_pointer);
	}
	return (NULL);
}

char	*strjoin_an_malloc(char *s1, char *s2, int size_of_s1, int size_of_s2)
{
	char	*str;

	while (s1 && s1[size_of_s1] != '\0')
		size_of_s1++;
	while (s2 && s2[size_of_s2] != '\0')
		size_of_s2++;
	str = (char *)malloc((size_of_s1 + size_of_s2 + 1) * sizeof(char));
	if (!str || size_of_s1 + size_of_s2 == 0)
		return (free_those(s1, str));
	size_of_s1 = 0;
	while (s1 && s1[size_of_s1] != '\0')
	{
		str[size_of_s1] = s1[size_of_s1];
		size_of_s1++;
	}
	size_of_s2 = 0;
	while (s2 && s2[size_of_s2] != '\0' && size_of_s2 != BUFFER_SIZE)
		str[size_of_s1++] = s2[size_of_s2++];
	free_those(s1, NULL);
	str[size_of_s1] = '\0';
	return (str);
}

char	*get_ok_ln(char *char_rding,
	int *nb_ln_looking, char *char_rd, int nb_char_rd)
{
	char	*return_val;
	int		finish;

	finish = 0;
	free(char_rding);
	*nb_ln_looking = *nb_ln_looking + 1;
	return_val = copy_line(find_new_line(char_rd,
				*nb_ln_looking - 1, nb_char_rd, &finish), 0);
	// if (!return_val)
	// 	return (free_those(char_rd, NULL));
	return (return_val);
}

char	*get_next_line(int fd)
{
	char			*char_rding;
	static char		*char_rd;
	int				nb_char_rd;
	static int		nb_ln_looking = 0;
	static int		finish = 0;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (char_rd)
			free (char_rd);
		char_rd = NULL;
		nb_ln_looking = 0;
		finish = 0;
		return (NULL);
	}
	char_rding = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!char_rding)
		return (free_those(char_rd, NULL));
	nb_char_rd = read(fd, char_rding, BUFFER_SIZE);
	if (nb_char_rd > 0)
		finish = 0;
	while (nb_char_rd > 0 && finish != 1)
	{
		char_rding[nb_char_rd] = '\0';
		char_rd = strjoin_an_malloc(char_rd, char_rding, 0, 0);
		if (!char_rd)
			return (free_those(char_rding, NULL));
		if (find_new_line(char_rd, nb_ln_looking, nb_char_rd, &finish))
			return (get_ok_ln(char_rding, &nb_ln_looking, char_rd, nb_char_rd));
		nb_char_rd = read(fd, char_rding, BUFFER_SIZE);
	}
	if (nb_char_rd != -1 && char_rd != NULL)
		if (find_new_line(char_rd, nb_ln_looking, nb_char_rd, &finish))
			return (get_ok_ln(char_rding, &nb_ln_looking, char_rd, nb_char_rd));
	if (char_rd)
		free (char_rd);
	free_those(char_rding, NULL);
	char_rd = NULL;
	nb_ln_looking = 0;
	finish = 0;
	return (NULL);
	// return (free_those(char_rding, char_rd));
}

// #include <fcntl.h>
// #include <stdio.h>

// int main()
// {
// 	int fd;
// 	char *str;
// 	size_t i;

// 	fd = open("./file" , O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	close(fd);

// 	fd = open("./file" , O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	// i  = 0;
// 	// while (str)
// 	// {
// 	// 	printf("%s", str);
// 	// 	free(str);
// 	// 	str = get_next_line(fd);
// 	// 	i++;
// 	// }
// 	// str = get_next_line(fd);
// 	close(fd);
// 	// system("leaks a.out");
// 	return (0);

// }
