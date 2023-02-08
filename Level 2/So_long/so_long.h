/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:48:20 by sboulain          #+#    #+#             */
/*   Updated: 2023/02/08 20:50:55 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mega_libft/libft.h"
# include "mlx/mlx.h"
// for close
# include <unistd.h>
// for math function
# include <math.h>
// for open
# include <fcntl.h>
// for bool
# include <stdbool.h>
// for malloc and free
# include <stdlib.h>

typedef struct s_cell
{
	bool	play_can_access;
	bool	has_player;
	bool	has_enemy;
	char	type;

}	t_cell;

typedef struct s_map
{
	t_cell	**cells;
	int		max_index_x_right;
	int		max_index_y_down;
	int		index_of_player_x;
	int		index_of_player_y;

}	t_map;

typedef struct s_coordinate
{
	int	x;
	int	y;
}	t_coordinate;

bool	is_map_valid_char(char *map_string);

void	print_map(t_map	*map);

void	free_map_cells(t_map *map);

t_map	*make_map(char	*map_string);

bool	check_flud_fill_main(t_map **map);



#endif