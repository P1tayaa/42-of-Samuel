/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:19:44 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/24 18:10:58 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

char	*copy_line(const char *s)
{
	char	*dupstr;
	int		i;
	
	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	dupstr = (char *)malloc((i + 1) * sizeof(char));
	if (!dupstr)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		dupstr[i] = s[i];
		i++;
	}
	dupstr[i] = '\n';
	dupstr[i + 1] = '\0';
	return (dupstr);
}


char	*find_new_line(char * buffer, int number_line)
{
	size_t	i;
	int 	current_number_line;
	char	*start_current_line_pointer;

	i = 0;
	current_number_line = 0;
	start_current_line_pointer = buffer;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			if(current_number_line == number_line)
				return(start_current_line_pointer);
			current_number_line++;
			start_current_line_pointer = &buffer[i + 1];
		}
		i++;
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
	while (s1[size_of_s1] != '\0')
		size_of_s1++;
	while (s2[size_of_s2] != '\0')
		size_of_s2++;
	if (size_of_s1 + size_of_s2 == 0)
		return (NULL);
	str = (char *)malloc((size_of_s1 + size_of_s2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	size_of_s1 = 0;
	while (s1[size_of_s1])
	{
		str[size_of_s1] = s1[size_of_s1];
		size_of_s1++;
	}
	size_of_s2 = 0;
	while (s2[size_of_s2])
	{
		str[size_of_s1] = s1[size_of_s2];
		size_of_s1++;
		size_of_s2++;
	}
	free(s1);
	
	return (str);
}


char	*get_next_line(int fd)
{
	char			*char_reading;
	static char		*char_read;
	char			*return_line;
	size_t			number_char_read;
	int				number_of_line_looking;
	
	unsigned long	i;
	
	char_reading = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	i = 1;
	
	number_of_line_looking = 4;

	number_char_read = 1;
	while(number_char_read != 0)
	{
		// read(fd, char_read, BUFFER_SIZE);
		number_char_read = read(fd, char_reading, BUFFER_SIZE);
		char_read = strjoin_an_malloc(char_read, char_reading);
		if(find_new_line(char_read, number_of_line_looking))
		{
			return_line =copy_line(find_new_line(char_read, number_of_line_looking));
			free(char_reading);
			free(char_read);
			return (return_line);
		}
		return (0);
	}
	// write(1, char_read, 10);
	free(char_read);
	return (NULL);
}


#include <fcntl.h>

int main()
{
	int fd;
	fd = open("./file.text" , O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
	printf("");
	return (0);

}
