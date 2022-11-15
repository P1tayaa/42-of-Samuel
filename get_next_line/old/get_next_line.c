/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:37:09 by sboulain          #+#    #+#             */
/*   Updated: 2022/11/15 18:39:34 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

#include <stdio.h>

char	*revome_fist_line_in_buffer(char *buffer)
{
	size_t	len_line;
	size_t	len_buffer;
	char	*new_buffer;
	
	len_line = 0;
	len_buffer = 0;
	while (buffer[len_line] != '\n')
		len_line++;
	while (buffer[len_buffer] != '\0')
		len_buffer++;
	new_buffer = (char *)malloc(len_buffer - len_line + 1);
	len_line++;
	len_buffer = 0;
	while (buffer[len_line] != '\0')
	{
		new_buffer[len_buffer] = buffer[len_line];
		len_buffer++;
		len_line++;
	}
	buffer[len_buffer] = '\0';
	if (buffer)
		free(buffer);
	return (new_buffer);
}

int	get_first_line_len(char *buffer)
{
	size_t	len_line;

	len_line = 0;
	while (buffer[len_line] != '\0')
	{
		if (buffer[len_line] == '\n')
			return (len_line);
		len_line++;
	}
	return (0);
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

char	*get_next_line(int fd)
{
	static char *buffer = NULL;
	char		*read_str;
	int 		buffer_read_len;

	if (buffer == NULL)
	{
		read_str = malloc(BUFFER_SIZE + 1);
		if (!read_str)
			return (NULL);
		buffer_read_len = read(fd, read_str, BUFFER_SIZE);
		read_str[buffer_read_len] = '\0';
		buffer = strjoin_an_malloc(buffer, read_str);
	}
	while (1)
	{
		if (get_first_line_len(buffer) != 0)
		{
			char		*line;
			int 		i = 0;
			int 		len_line = get_first_line_len(buffer);
			line = malloc(len_line * sizeof(char));
			while (i < len_line)
			{
				line[i] = buffer[i];
				i++;
			}
			line[i] = '\0';
			revome_fist_line_in_buffer(buffer);
			return (line);
		}
		else
		{
			if (read_str)
				free(read_str);
			read_str = malloc(BUFFER_SIZE + 1);
			buffer_read_len = read(fd, read_str, BUFFER_SIZE);
			read_str[buffer_read_len] = '\0';

			if (buffer_read_len != 0)
				buffer = strjoin_an_malloc(buffer, read_str);
			if (buffer_read_len < BUFFER_SIZE)
				return (buffer);
		}
	}
	return (NULL);
}

#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd;
	char *str;
	size_t i;

	// str = malloc(10);
	// while (i < 9)
	// {
	// 	str[i] = i + '0';
	// 	i++;
	// }
	// str[4] = '\n';
	// str[i] = '\0';
	// str = revome_fist_line_in_buffer(str);
	// printf("%s", str);
	// free(str);
	

	fd = open("./file" , O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	fd = open("./file" , O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	i  = 0;
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
		i++;
	}
	str = get_next_line(fd);
	close(fd);
	system("leaks a.out");
	return (0);

}
