/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:19:44 by sboulain          #+#    #+#             */
/*   Updated: 2022/11/03 19:40:17 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*copy_line(const char *s)
{
	char	*dupstr;
	int		i;
	int		did_new_line;

	did_new_line = 0;
	if (!s)
		return (NULL);
	i = 0;
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

char	*find_new_line(char *buffer, int number_line, size_t number_char_read, int *didfinish)
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
			if (number_line == 0)
				return(buffer);
			if(current_number_line == number_line){
				return(start_current_line_pointer);
				}
			current_number_line++;
			start_current_line_pointer = &buffer[i + 1];
		}
		i++;
	}
	if (buffer[i] == '\0' && number_char_read == 0 && *didfinish != 1)
	{
		*didfinish = 1;
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


char	*get_next_line(int fd)
{
	char			*char_reading;
	static char		*char_read = NULL;
	int				number_char_read;
	static int		number_of_line_looking = 0;
	static int		didfinish = 0;
	
	unsigned long	i;
	
	if(fd < 0)
		return (NULL);
	char_reading = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!char_reading)
	{
		if (char_read)
			free (char_read);
		return (NULL);
	}
	i = 1;
	number_char_read = read(fd, char_reading, BUFFER_SIZE);
	if (number_char_read > 0)
		didfinish = 0;
	while(number_char_read > 0 && didfinish != 1)
	{
		char_reading[number_char_read] = '\0';
		char_read = strjoin_an_malloc(char_read, char_reading);
		if (!char_read)
		{
			free(char_reading);
			return (NULL);
		}
		if(find_new_line(char_read, number_of_line_looking, number_char_read, &didfinish) != NULL)
		{
			didfinish = 0;
			free(char_reading);
			number_of_line_looking++;
			return (copy_line(find_new_line(char_read, number_of_line_looking - 1, number_char_read, &didfinish)));
		}
		number_char_read = read(fd, char_reading, BUFFER_SIZE);
	}
	if (number_char_read != -1 && char_read != NULL)
		if(find_new_line(char_read, number_of_line_looking, number_char_read, &didfinish) != NULL)
		{
			didfinish = 0;
			free(char_reading);
			number_of_line_looking++;
			return (copy_line(find_new_line(char_read, number_of_line_looking - 1, number_char_read, &didfinish)));
		}
	free(char_reading);
	// write(1, char_read, 10);
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
