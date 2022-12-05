/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:37:09 by sboulain          #+#    #+#             */
/*   Updated: 2022/12/05 11:26:32 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

#include <stdio.h>

char	*free_those(char *char_rd, char *char_rding)
{
	if (char_rd != NULL)
	{
		free(char_rd);
		char_rd = NULL;	
	}
	if (char_rding != NULL)
	{
		free(char_rding);
		char_rding = NULL;
	}
	return (NULL);
}

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
	if (!(new_buffer = (char *) malloc(len_buffer - len_line + 1)))
		return (NULL);
	len_line++;
	len_buffer = 0;
	while (buffer[len_line] != '\0')
	{
		new_buffer[len_buffer] = buffer[len_line];
		len_buffer++;
		len_line++;
	}
	new_buffer[len_buffer] = '\0';
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

char	*get_next_line(int fd)
{
	static char *buffer = NULL;
	char		read_str[BUFFER_SIZE + 1];
	int 		buffer_read_len;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer)
			free (buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer_read_len = read(fd, read_str, BUFFER_SIZE);
	read_str[buffer_read_len] = '\0';
	if (buffer_read_len != 0)
		buffer = strjoin_an_malloc(buffer, read_str, 0, 0);
	while (buffer != NULL)
	{
		if (get_first_line_len(buffer) != 0)
		{
			char		*line;
			int 		i;
			int 		len_line;
			i = 0;
			len_line = get_first_line_len(buffer);
			// printf("%d/n", i);
			if (!(line = malloc(len_line + 1 * sizeof(char))))
				return (NULL);
			while (i <= len_line)
			{
				line[i] = buffer[i];
				i++;
			}
			line[i] = '\0';
			if (!(buffer = revome_fist_line_in_buffer(buffer)))
				return (NULL);
			return (line);
		}
		//read line
		if (buffer_read_len == BUFFER_SIZE)
		{
			buffer_read_len = read(fd, read_str, BUFFER_SIZE);
			read_str[buffer_read_len] = '\0';
		}
		if (buffer_read_len != 0)
			buffer = strjoin_an_malloc(buffer, read_str, 0, 0);
		printf("{%s}\n", buffer);
		if (buffer_read_len < BUFFER_SIZE)
		{
			char *str;
			int	i;
			
			i = 0;
			while (buffer != NULL && buffer[i] != '\0')
				i++;
			str = (char *) malloc(i + 1 * sizeof(char));
			if (!str)
				return (NULL);
			i = 0;
			// printf
			while (buffer != NULL && buffer[i] != '\0')
			{
				str[i] = buffer[i];
				i++;
			}
			str[i] = '\0';
			if (buffer)
				free(buffer);
			buffer = NULL;
			// free_those(buffer, NULL);
			return (str);
		}
		// if (buffer_read_len == 0)
		// 	buffer = free_those(buffer, NULL);
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

	fd = open("./file" , O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = NULL;
		str = get_next_line(fd);
		// printf("%s", str);
		// free(str);
		// str = get_next_line(fd);
		// i++;
	}
	str = get_next_line(fd);
	close(fd);
	// system("leaks a.out");
	return (0);
}
