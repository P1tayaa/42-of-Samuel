/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:42:00 by sboulain          #+#    #+#             */
/*   Updated: 2023/06/01 16:19:08 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_free_texture(t_texture_images *textures_pointers);

mlx_image_t	*make_image_for_player(
		t_texture_images *textures_pointers, mlx_t **mlx, int x, int y)
{
	mlx_image_t	*new_images_player;
	int			size;

	size = 16;
	if (x == 1)
		new_images_player = mlx_texture_to_image(
				*mlx, textures_pointers->player_right);
	else if (x == -1)
		new_images_player = mlx_texture_to_image(
				*mlx, textures_pointers->player_left);
	else if (y == 1)
		new_images_player = mlx_texture_to_image(
				*mlx, textures_pointers->player_back);
	else if (y == -1)
		new_images_player = mlx_texture_to_image(
				*mlx, textures_pointers->player_front);
	if (!new_images_player)
		error_free_texture(textures_pointers);
	if (!mlx_resize_image(new_images_player, size, size))
		error_free_texture(textures_pointers);
	return (new_images_player);
}

void	terminate_texture(t_texture_images *texture_pouinter);

void	item_manger(t_param_for_hook *param_hooks)
{
	param_hooks->step_done++;
	ft_printf("%d steps taken\n", param_hooks->step_done);
	if (param_hooks->map->cells[param_hooks->map->index_of_player_y]
		[param_hooks->map->index_of_player_x].type == 'C')
	{
		mlx_delete_image(param_hooks->mlx, param_hooks->map->cells
		[param_hooks->map->index_of_player_y]
		[param_hooks->map->index_of_player_x].object);
			param_hooks->map->coin_left--;
		ft_printf("%d brush left\n", param_hooks->map->coin_left);
		param_hooks->map->cells[param_hooks->map->index_of_player_y]
		[param_hooks->map->index_of_player_x].type = '0';
	}
	if (param_hooks->map->cells[param_hooks->map->index_of_player_y]
		[param_hooks->map->index_of_player_x].type == 'E')
	{
		if (param_hooks->map->coin_left <= 0)
		{
			ft_printf("gg\n");
			terminate_texture(param_hooks->textures_pointers);
			mlx_terminate(param_hooks->mlx);
			exit (0);
		}
	}
}

void	moving_image_of_player(int x, int y, t_param_for_hook *param_hooks)
{
	mlx_image_t	*new_images_player;
	int			size;

	size = 16;
	new_images_player = make_image_for_player(
			param_hooks->textures_pointers, &param_hooks->mlx, x, y);
	mlx_delete_image(param_hooks->mlx, param_hooks->map->cells
	[param_hooks->map->index_of_player_y][param_hooks->map->index_of_player_x]
		.player);
	param_hooks->map->index_of_player_x
		= param_hooks->map->index_of_player_x + x;
	param_hooks->map->index_of_player_y
		= param_hooks->map->index_of_player_y - y;
	param_hooks->map->cells
	[param_hooks->map->index_of_player_y][param_hooks->map->index_of_player_x]
		.player = new_images_player;
	item_manger(param_hooks);
	if (mlx_image_to_window(param_hooks->mlx, new_images_player,
			param_hooks->map->index_of_player_x * size,
			param_hooks->map->index_of_player_y * size) < 0)
		error_free_texture(param_hooks->textures_pointers);
	usleep(50000);
}

void	player_moves(int x, int y, t_param_for_hook *param_hooks)
{
	mlx_image_t	*new_images_player;

	if (param_hooks->map->cells
		[param_hooks->map->index_of_player_y - y]
		[param_hooks->map->index_of_player_x + x].type == '1')
	{
		new_images_player = make_image_for_player(
				param_hooks->textures_pointers, &param_hooks->mlx, x, y);
		mlx_delete_image(param_hooks->mlx, param_hooks->map->cells
		[param_hooks->map->index_of_player_y]
		[param_hooks->map->index_of_player_x]
			.player);
		param_hooks->map->cells
		[param_hooks->map->index_of_player_y]
		[param_hooks->map->index_of_player_x]
			.player = new_images_player;
		if (mlx_image_to_window(param_hooks->mlx, new_images_player,
				param_hooks->map->index_of_player_x * 16,
				param_hooks->map->index_of_player_y * 16) < 0)
			error_free_texture(param_hooks->textures_pointers);
		return ;
	}
	moving_image_of_player(x, y, param_hooks);
}
