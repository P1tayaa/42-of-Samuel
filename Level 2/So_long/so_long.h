/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:48:20 by sboulain          #+#    #+#             */
/*   Updated: 2023/05/28 19:59:42 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mega_libft/libft.h"
// include MLX42
# include "MLX42/include/MLX42/MLX42.h"
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
	mlx_image_t	*background;
	mlx_image_t	*object;
	mlx_image_t	*player;

}	t_cell;

typedef struct s_map
{
	t_cell		**cells;
	int			max_index_x_right;
	int			max_index_y_down;
	int			index_of_player_x;
	int			index_of_player_y;	

}	t_map;

typedef struct s_coordinate
{
	int	x;
	int	y;
}	t_coordinate;

typedef struct s_source_images
{
	char	*background;
	char	*wall;
	char	*item;
	char	*exit;
	char	*player_front;
	char	*player_left;
	char	*player_right;
	char	*player_back;

}	t_source_images;

typedef struct s_texture_images
{
	mlx_texture_t	*background;
	mlx_texture_t	*wall;
	mlx_texture_t	*item;
	mlx_texture_t	*exit;
	mlx_texture_t	*player_front;
	mlx_texture_t	*player_left;
	mlx_texture_t	*player_right;
	mlx_texture_t	*player_back;

}	t_texture_images;

typedef struct s_image_images
{
	mlx_image_t	*background;
	mlx_image_t	*wall;
	mlx_image_t	*item;
	mlx_image_t	*exit;
	mlx_image_t	*player_front;
	mlx_image_t	*player_left;
	mlx_image_t	*player_right;
	mlx_image_t	*player_back;

}	t_image_images;

bool	is_map_valid_char(char *map_string);

void	print_map(t_map	*map);

void	free_map_cells(t_map *map);

t_map	*make_map(char	*map_string);

bool	check_flud_fill_main(t_map **map);



#endif