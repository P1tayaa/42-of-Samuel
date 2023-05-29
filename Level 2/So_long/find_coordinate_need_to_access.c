/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_coordinate_need_to_access.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:41:16 by sboulain          #+#    #+#             */
/*   Updated: 2023/05/29 20:45:32 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_count_coo(t_map *map, const char *need_to_access)
{
	int				i;
	int				j;
	int				count_coo;

	count_coo = 0;
	i = 0;
	while (i <= map ->max_index_y_down)
	{
		j = 0;
		while (j <= map ->max_index_x_right)
		{
			if (map ->cells[i][j].type == need_to_access[0]
				|| map ->cells[i][j].type == need_to_access[1])
				count_coo++;
			j++;
		}
		i++;
	}
	return (count_coo);
}

t_coordinate	*make_coordinates_need_to_access(int count_coo,
	t_map *map, const char *need_to_access)
{
	int				i;
	int				j;
	t_coordinate	*need_to_access_coo;

	need_to_access_coo = malloc((count_coo + 1) * sizeof(t_coordinate));
	i = 0;
	count_coo = 0;
	while (i <= map ->max_index_y_down)
	{
		j = -1;
		while (++j <= map ->max_index_x_right)
		{
			if (map ->cells[i][j].type == need_to_access[0]
				|| map ->cells[i][j].type == need_to_access[1])
			{
				need_to_access_coo[count_coo].y = i;
				need_to_access_coo[count_coo].x = j;
				count_coo++;
			}
		}
		i++;
	}
	need_to_access_coo[count_coo].y = -1;
	need_to_access_coo[count_coo].x = -1;
	return (need_to_access_coo);
}

t_coordinate	*find_coordinate_need_to_access(t_map *map)
{
	const char		*need_to_access = "EC";
	int				i;
	int				j;
	int				count_coo;
	t_coordinate	*need_to_access_coo;

	count_coo = get_count_coo(map, need_to_access);
	(*map).coin_left = count_coo - 1;
	need_to_access_coo = make_coordinates_need_to_access(
			count_coo, map, need_to_access);
	return (need_to_access_coo);
}
