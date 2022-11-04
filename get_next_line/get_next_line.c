/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:19:44 by sboulain          #+#    #+#             */
/*   Updated: 2022/11/04 20:55:36 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		char *buffer, int number_line, size_t nb_char_read, int *finish)
{
	size_t	i;
	int		current_number_line;
	char	*start_current_line_pointer;

	i = 0;
	current_number_line = 0;
	start_current_line_pointer = buffer;
	while (buffer[i])
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
	if (buffer[i] == '\0' && nb_char_read == 0 && *finish != 1)
	{
		*finish = 1;
		return (start_current_line_pointer);
	}
	return (NULL);
}

char	*strjoin_an_malloc(char *s1, char *s2)
{
	char	*str;
	size_t	size_of_s1;
	size_t	size_of_s2;

	size_of_s1 = 0;
	size_of_s2 = 0;
	while (s1 && s1[size_of_s1] != '\0')
		size_of_s1++;
	while (s2 && s2[size_of_s2] != '\0')
		size_of_s2++;
	if (size_of_s1 + size_of_s2 == 0)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	str = (char *)malloc((size_of_s1 + size_of_s2 + 1) * sizeof(char));
	if (!str)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	size_of_s1 = 0;
	while (s1 && s1[size_of_s1] != '\0')
	{
		str[size_of_s1] = s1[size_of_s1];
		size_of_s1++;
	}
	size_of_s2 = 0;
	while (s2 && s2[size_of_s2] != '\0' && size_of_s2 != BUFFER_SIZE)
	{
		str[size_of_s1] = s2[size_of_s2];
		size_of_s1++;
		size_of_s2++;
	}
	if (s1)
		free(s1);
	str[size_of_s1] = '\0';
	return (str);
}

char	*get_right_line(char *char_reading,
	int nb_ln_looking, char *char_read, int nb_char_read)
{
	char	*return_val;
	int		finish;

	finish = 0;
	free(char_reading);
	nb_ln_looking++;
	return_val = copy_line
		(find_new_line(char_read, nb_ln_looking - 1, nb_char_read, &finish), 0);
	if (return_val == NULL)
	{
		free (char_read);
		return (NULL);
	}
	return (return_val);
}

int	fd_open_close_fix(int fd, char *char_reading,
	char *char_read, int *nb_char_read)
{
	size_t	i;

	if (!char_read)
		return (1);
	if (!char_reading)
		return (1);
	i = 0;
	while (char_reading[i] != '\0' && char_read[i] != '\0')
	{
		if (char_reading[i] != char_read[i])
			return (1);
		i++;
	}
	free (char_reading);
	char_reading = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!char_reading)
		return (0);
	*nb_char_read = read(fd, char_reading, BUFFER_SIZE);
	return (fd_open_close_fix(fd, char_reading, char_read, nb_char_read));
}

char	*get_next_line(int fd)
{
	char			*char_reading;
	static char		*char_read = NULL;
	int				nb_char_read;
	static int		nb_ln_looking = 0;
	static int		finish = 0;

	if (fd < 0)
		return (NULL);
	char_reading = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!char_reading)
	{
		if (char_read)
			free (char_read);
		return (NULL);
	}
	nb_char_read = read(fd, char_reading, BUFFER_SIZE);
	// if (fd_open_close_fix(fd, char_reading, char_read, &nb_char_read) != 1)
	// {
	// 	if (char_read)
	// 		free (char_read);
	// 	return (NULL);
	// }
	if (nb_char_read > 0)
		finish = 0;
	while (nb_char_read > 0 && finish != 1)
	{
		char_reading[nb_char_read] = '\0';
		char_read = strjoin_an_malloc(char_read, char_reading);
		if (!char_read)
		{
			free(char_reading);
			return (NULL);
		}
		if (!find_new_line(char_read, nb_ln_looking, nb_char_read, &finish))
			return (get_right_line(char_reading, nb_ln_looking,
					char_read, nb_char_read));
		nb_char_read = read(fd, char_reading, BUFFER_SIZE);
	}
	if (nb_char_read != -1 && char_read != NULL)
		if (!find_new_line(char_read, nb_ln_looking, nb_char_read, &finish))
			return (get_right_line(char_reading, nb_ln_looking,
					char_read, nb_char_read));
	if (char_reading)
		free(char_reading);
	if (char_read)
		free(char_read);
	return (NULL);
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
