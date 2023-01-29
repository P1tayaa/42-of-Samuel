/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:37:09 by sboulain          #+#    #+#             */
/*   Updated: 2022/12/10 18:45:00 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*free_and_return_dup_buffer(char **buffer, int i)
{
	char	*str;

	if ((*buffer)[0] == '\0')
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	while ((*buffer) != NULL && (*buffer)[i] != '\0')
		i++;
	str = (char *) malloc(i + 1 * sizeof(char));
	if (!str)
		return (free_those(buffer, NULL));
	i = 0;
	while ((*buffer) != NULL && (*buffer)[i] != '\0')
	{
		str[i] = (*buffer)[i];
		i++;
	}
	str[i] = '\0';
	if ((*buffer))
		free((*buffer));
	(*buffer) = NULL;
	return (str);
}

char	*return_new_line_refreash_buf(char **buffer)
{
	char		*line;
	int			i;
	int			len_line;

	i = 0;
	len_line = get_first_line_len(*buffer);
	line = malloc(len_line + 2 * sizeof(char));
	if (!(line))
		return (free_those(buffer, NULL));
	while (i <= len_line)
	{
		line[i] = (*buffer)[i];
		i++;
	}
	line[i] = '\0';
	*buffer = revome_fist_line_in_buffer((*buffer));
	if (!*buffer)
		return (free(line), NULL);
	return (line);
}

void	read_lines(int *buffer_read_len, int fd,
	char (*read_str)[BUFFER_SIZE + 1], char **buffer)
{
	*buffer_read_len = read(fd, *read_str, BUFFER_SIZE);
	if (*buffer_read_len != 0)
	{
		(*read_str)[*buffer_read_len] = '\0';
		*buffer = strjoin_an_malloc(*buffer, *read_str, 0, 0);
	}
}

char	*get_next_line(int fd)
{
	char		read_str[BUFFER_SIZE + 1];
	int			buffer_read_len;
	static char	*buffer = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free_those(&buffer, NULL));
	read_lines(&buffer_read_len, fd, &read_str, &buffer);
	while (buffer != NULL)
	{
		if (get_first_line_len(buffer) != -1)
			return (return_new_line_refreash_buf(&buffer));
		read_lines(&buffer_read_len, fd, &read_str, &buffer);
		if (buffer_read_len < BUFFER_SIZE && get_first_line_len(buffer) == -1)
			return (free_and_return_dup_buffer(&buffer, 0));
	}
	return (NULL);
}

// #include <fcntl.h>
// #include <stdio.h>

// int main()
// {
// 	int fd;
// 	char *str;
// 	char *str2;
// 	size_t i;

// 	fd = open("./file" , O_RDONLY);
// 	str = get_next_line(fd);
// 	while (str)
// 	{
// 		printf("{%s}\n", str);
// 		free(str);
// 		str = NULL;
// 		str = get_next_line(fd);
// 		// printf("%s", str);
// 		// free(str);
// 		// str = get_next_line(fd);
// 		// i++;
// 	}
// 	str = get_next_line(fd);
// 	close(fd);

// 	// str = malloc(6);
// 	// str2 = malloc(6);

// 	// i = 0;
// 	// while (i < 5)
// 	// {
// 	// 	str[i] = 'a' + i;
// 	// 	str2[i] = 'z' - i;
// 	// 	i++;
// 	// }
// 	// str [i] = '\0';
// 	// str2 [i] = '\0';
// 	// str = strjoin_an_malloc(str, str2, 0 , 0);
// 	// printf("%s\n",str);
// 	// free(str2);
// 	// free(str);

// 	// system("leaks a.out");
// 	return (0);
// }
