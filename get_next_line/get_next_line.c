/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:19:44 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/27 19:36:26 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

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


char	*find_new_line(char * buffer, int number_line, size_t number_char_read, int *didfinish)
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
			// printf("%d %d\n", number_line, current_number_line);
			if(current_number_line + 1 == number_line){
				// printf("%d %d\n", number_line, current_number_line);
				
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
		return (NULL);
	str = (char *)malloc((size_of_s1 + size_of_s2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
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
	// printf("%s\n",str);
	return (str);
}


char	*get_next_line(int fd)
{
	char			*char_reading;
	static char		*char_read;
	size_t			number_char_read;
	static int		number_of_line_looking = 0;
	static int		didfinish = 0;
	
	unsigned long	i;
	
	char_reading = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	i = 1;
	// printf("runing");
	number_char_read = read(fd, char_reading, BUFFER_SIZE);
	if (number_char_read > 0)
		didfinish = 0;
	while(number_char_read > 0 && didfinish != 1)
	{
		// read(fd, char_read, BUFFER_SIZE);
		char_reading[number_char_read] = '\0';
		// if (number_char_read == 0 && find_new_line(char_read, number_of_line_looking, number_char_read, &didfinish) == NULL)
		// 	break ;
		// printf("%u\n\n", number_char_read);
		char_read = strjoin_an_malloc(char_read, char_reading);
		// printf("%s %d\n", char_read, number_of_line_looking);
		if(find_new_line(char_read, number_of_line_looking, number_char_read, &didfinish) != NULL)
		{
			didfinish = 0;
			free(char_reading);
			number_of_line_looking++;
			return (copy_line(find_new_line(char_read, number_of_line_looking - 1, number_char_read, &didfinish)));
		}
		number_char_read = read(fd, char_reading, BUFFER_SIZE);
		// return (NULL);
	}
	if(find_new_line(char_read, number_of_line_looking, number_char_read, &didfinish) != NULL)
	{
		didfinish = 0;
		free(char_reading);
		number_of_line_looking++;
		return (copy_line(find_new_line(char_read, number_of_line_looking - 1, number_char_read, &didfinish)));
	}
	// write(1, char_read, 10);
	return (NULL);
}


// #include <fcntl.h>

// int main()
// {
// 	int fd;
// 	char *str;
	
// 	fd = open("./file" , O_RDONLY);
// 	// str = get_next_line(fd);
// 	while (1 == 1)
// 	{
// 		str = get_next_line(fd);
// 		if (str != NULL)
// 		{
// 			printf("%s", str);
// 			free(str);
// 		}
// 	}
// 	close(fd);
// 	// system("leaks a.out");
// 	return (0);

// }
