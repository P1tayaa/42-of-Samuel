/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 13:11:48 by sboulain          #+#    #+#             */
/*   Updated: 2023/02/05 15:03:27 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_lenght_of_first_line(char *map_string)
{
	int	i;

	i = 0;
	while (map_string[i] != '\n' && map_string[i] != '\0')
		i++;
	if (map_string[i] == '\0')
		return (-1);
	return (i);
}

bool	are_char_right(char single_char)
{
	const char	*all_possible_char = "10CEP";
	int			i;

	i = 0;
	while (all_possible_char[i] != '\0')
	{
		if (all_possible_char[i] == single_char)
			return (true);
		i++;
	}
	return (false);
}

bool	are_lines_good(char *map_string, int lenght_of_line)
{
	int	i;
	int	j;

	i = 0;
	while (map_string[i] != '\0')
	{
		j = 0;
		while (j < lenght_of_line)
		{
			if (map_string[i + j] == '\n' && are_char_right(map_string[i + j]))
				return (false);
			j++;
		}
		if (map_string[i + j] == '\0')
			return (true);
		if (map_string[i + j] != '\n')
			return (false);
		i = i + j + 1;
	}
	return (true);
}

bool	is_map_valid_char(char *map_string)
{
	int	lenght_of_line;

	lenght_of_line = get_lenght_of_first_line(map_string);
	if (lenght_of_line == -1)
		return (false);
	return (are_lines_good(map_string, lenght_of_line));
}
