/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_making_p2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:29:57 by sboulain          #+#    #+#             */
/*   Updated: 2023/05/29 20:30:28 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verctor_string_map_freeur(char **verctor_string_map)
{
	int	i;

	i = 0;
	while (verctor_string_map[i] != NULL)
	{
		free(verctor_string_map[i]);
		i++;
	}
	free(verctor_string_map);
	verctor_string_map = NULL;
}

t_cell	make_cell(char type)
{
	t_cell	cell;

	if (type == 'P')
	{
		cell.type = '0';
		cell.has_player = true;
		cell.has_enemy = false;
		cell.play_can_access = true;
		return (cell);
	}
	cell.type = type;
	cell.has_player = false;
	cell.has_enemy = false;
	cell.play_can_access = false;
	return (cell);
}

t_cell	*make_cell_row(char *line_string, int max_index_x_right)
{
	t_cell	*cells_row;
	int		i;

	cells_row = malloc(sizeof(t_cell) * (max_index_x_right + 1));
	i = 0;
	while (i <= max_index_x_right)
	{
		cells_row[i] = make_cell(line_string[i]);
		i++;
	}
	return (cells_row);
}

int	get_how_many_y_down(char **verctor_string_map)
{
	int	i;

	i = 0;
	while (verctor_string_map[i] != NULL)
	{
		i++;
	}
	return (i - 1);
}

int	get_how_many_x_right(char **verctor_string_map)
{
	int	i;

	i = 0;
	while (verctor_string_map[0][i] != '\0')
	{
		i++;
	}
	return (i - 1);
}
