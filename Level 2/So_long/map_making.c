/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_making.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:48:03 by sboulain          #+#    #+#             */
/*   Updated: 2023/05/29 20:31:12 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verctor_string_map_freeur(char **verctor_string_map);

t_cell	make_cell(char type);

t_cell	*make_cell_row(char *line_string, int max_index_x_right);

int		get_how_many_y_down(char **verctor_string_map);

int		get_how_many_x_right(char **verctor_string_map);

// void	print_map(t_map	*map)
// {
// 	int	i;
// 	int	j;

// 	ft_printf("x = %d, y = %d \n",
// 		map ->max_index_x_right, map ->max_index_y_down);
// 	i = 0;
// 	while (i <= map ->max_index_y_down)
// 	{
// 		j = 0;
// 		while (j <= map ->max_index_x_right)
// 		{
// 			if (i == map->index_of_player_y && j == map->index_of_player_x)
// 				ft_printf("P");
// 			else
// 				ft_printf("%c", map ->cells[i][j].type);
// 			j++;
// 		}
// 		ft_printf("%c", '\n');
// 		i++;
// 	}
// }

void	free_map_cells(t_map *map)
{
	int	i;

	i = 0;
	while (i <= map ->max_index_y_down)
	{
		free(map ->cells[i]);
		map ->cells[i] = NULL;
		i++;
	}
	free(map ->cells);
	map ->cells = NULL;
	free(map);
}

t_map	*make_map(char	*map_string)
{
	t_map	*map;
	char	**verctor_string_map;
	int		i;

	map = malloc(sizeof(t_map));
	verctor_string_map = ft_split(map_string, '\n');
	map -> max_index_x_right = get_how_many_x_right(verctor_string_map);
	map -> max_index_y_down = get_how_many_y_down(verctor_string_map);
	map -> cells = (t_cell **)malloc
		((map ->max_index_y_down + 1) * sizeof(t_cell *));
	if (map -> cells == NULL)
		exit(1);
	i = 0;
	while (i <= map -> max_index_y_down)
	{
		map -> cells[i] = make_cell_row
			(verctor_string_map[i], map ->max_index_x_right);
		i++;
	}
	verctor_string_map_freeur(verctor_string_map);
	return (map);
}
