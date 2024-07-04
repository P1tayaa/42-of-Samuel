/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:35:30 by sboulain          #+#    #+#             */
/*   Updated: 2024/07/04 14:05:15 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/get_next_line.h"

char	*free_those(char **char_rd, char **char_rding)
{
	if (*char_rd != NULL)
	{
		free(*char_rd);
		*char_rd = NULL;
	}
	if (*char_rd != NULL)
	{
		free(*char_rding);
		*char_rding = NULL;
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
	new_buffer = (char *) malloc(len_buffer - len_line + 1);
	if (!new_buffer)
		return (free_those(&buffer, NULL));
	len_line++;
	len_buffer = 0;
	while (buffer[len_line] != '\0')
	{
		new_buffer[len_buffer] = buffer[len_line];
		len_buffer++;
		len_line++;
	}
	free_those(&buffer, NULL);
	new_buffer[len_buffer] = '\0';
	return (new_buffer);
}

int	get_first_line_len(char *buffer)
{
	int	len_line;

	len_line = 0;
	while (buffer[len_line] != '\0')
	{
		if (buffer[len_line] == '\n')
			return (len_line);
		len_line++;
	}
	return (-1);
}

char	*strjoin_an_malloc(char *s1, char *s2, int size_of_s1, int size_of_s2)
{
	char	*str;

	while (s1 && s1[size_of_s1] != '\0')
		size_of_s1++;
	while (s2 && s2[size_of_s2] != '\0')
		size_of_s2++;
	str = (char *)malloc((size_of_s1 + size_of_s2 + 1) * sizeof(char));
	if (!str)
		return (free_those(&s1, NULL));
	size_of_s1 = 0;
	while (s1 && s1[size_of_s1] != '\0')
	{
		str[size_of_s1] = s1[size_of_s1];
		size_of_s1++;
	}
	size_of_s2 = 0;
	while (s2 && s2[size_of_s2] != '\0')
		str[size_of_s1++] = s2[size_of_s2++];
	if (s1)
		free(s1);
	s1 = NULL;
	str[size_of_s1] = '\0';
	return (str);
}
