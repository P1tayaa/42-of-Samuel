/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flud_fill_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:33:23 by sboulain          #+#    #+#             */
/*   Updated: 2023/06/01 18:45:24 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coordinate	*find_coordinate_need_to_access(t_map *map);

// void	print_coordinate_vertor(t_coordinate *coo, t_map *map)
// {
// 	int	i;

// 	i = 0;
// 	while (coo[i].x != -1)
// 	{
// 		ft_printf("coordiante are: %d, %d, type = %c\n",
//		coo[i].x, coo[i].y, map -> cells[coo[i].y][coo[i].x].type);
// 		i++;
// 	}
// }

//make all the accessible actually accessible
void	check_if_side_are_accessible(int x, int y, t_map **map)
{
	if ((*map)-> cells[y][x].play_can_access == false
		&& (*map)->cells[y][x].type != '1')
		(*map)-> cells[y][x].play_can_access = true;
	if (x > 0 && (*map)->cells[y][x - 1].play_can_access == false
		&& (*map)-> cells[y][x - 1].type != '1')
		check_if_side_are_accessible(x - 1, y, map);
	if (x < (*map)-> max_index_x_right
		&& (*map)->cells[y][x + 1].play_can_access == false
			&& (*map)->cells[y][x + 1].type != '1')
		check_if_side_are_accessible(x + 1, y, map);
	if (y > 0 && (*map)->cells[y - 1][x].play_can_access == false
		&& (*map)-> cells[y - 1][x].type != '1')
		check_if_side_are_accessible(x, y - 1, map);
	if (y < (*map)-> max_index_y_down
		&& (*map)->cells[y + 1][x].play_can_access == false &&
			(*map)-> max_index_y_down && (*map)-> cells[y + 1][x].type != '1')
		check_if_side_are_accessible(x, y + 1, map);
}

void	print_map_fill(t_map *map)
{
	int	i;
	int	j;

	ft_printf("x = %d, y = %d \n",
		map ->max_index_x_right, map ->max_index_y_down);
	i = 0;
	while (i <= map ->max_index_y_down)
	{
		j = 0;
		while (j <= map ->max_index_x_right)
		{
			if (map ->cells[i][j].play_can_access == true)
				ft_printf("O");
			else if (i == map->index_of_player_y && j == map->index_of_player_x)
				ft_printf("P");
			else
				ft_printf("%c", map ->cells[i][j].type);
			j++;
		}
		ft_printf("%c", '\n');
		i++;
	}
}

bool	is_need_to_access_acessible(t_coordinate *need_to_access, t_map *map)
{
	int	i;

	i = 0;
	while (need_to_access[i].x != -1)
	{
		if
		(map ->cells[need_to_access[i].y][need_to_access[i].x].play_can_access
			== false)
			return (false);
		i++;
	}
	return (true);
}

bool	check_flud_fill_main(t_map **map)
{
	t_coordinate	*need_to_access_coo;
	bool			return_val;

	need_to_access_coo = find_coordinate_need_to_access(*map);
	check_if_side_are_accessible((*map)->index_of_player_x,
		(*map)->index_of_player_y, map);
	return_val = is_need_to_access_acessible(need_to_access_coo, *map);
	free(need_to_access_coo);
	return (return_val);
}
