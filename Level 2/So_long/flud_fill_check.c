/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flud_fill_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:33:23 by sboulain          #+#    #+#             */
/*   Updated: 2023/02/08 20:46:57 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coordinate	*find_coordinate_need_to_access(t_map *map)
{
	const char		*need_to_access = "EC";
	int				i;
	int				j;
	int				count_coo;
	t_coordinate	*need_to_access_coo;

	i = 0;
	count_coo = 0;
	while (i <= map ->max_index_y_down)
	{
		j = 0;
		while (j <= map ->max_index_x_right)
		{
			if (map ->cells[i][j].type == need_to_access[0] || map ->cells[i][j].type == need_to_access[1])
				count_coo++;
			j++;
		}
		i++;
	}
	need_to_access_coo = (t_coordinate *)malloc((count_coo + 1) * sizeof(t_coordinate));
	i = 0;
	count_coo = 0;
	while (i <= map ->max_index_y_down)
	{
		j = 0;
		while (j <= map ->max_index_x_right)
		{
			if (map ->cells[i][j].type == need_to_access[0] || map ->cells[i][j].type == need_to_access[1])
				{
					need_to_access_coo[count_coo].y = i;
					need_to_access_coo[count_coo].x = j;
					count_coo++;
				}
			j++;
		}
		i++;
	}
	need_to_access_coo[count_coo].y = -1;
	need_to_access_coo[count_coo].x = -1;
	return (need_to_access_coo);
}

void	print_coordinate_vertor(t_coordinate *coo, t_map *map)
{
	int i;

	i = 0;
	while (coo[i].x != -1)
	{
		ft_printf("coordiante are: %d, %d, type = %c\n", coo[i].x, coo[i].y, map -> cells[coo[i].y][coo[i].x].type);
		i++;
	}
}

//make all the accessible actually accessible
void	check_if_side_are_accessible(int x, int y, t_map **map)
{
	// ft_printf("x %d, y %d\n", x, y);
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
	print_coordinate_vertor(need_to_access_coo, *map);
	check_if_side_are_accessible((*map)->index_of_player_x, (*map)->max_index_y_down, map);

	print_map_fill(*map);
	return_val = is_need_to_access_acessible(need_to_access_coo, *map);
	free(need_to_access_coo);
	return (return_val);
}
