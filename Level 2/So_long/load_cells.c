/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_cells.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:09:17 by sboulain          #+#    #+#             */
/*   Updated: 2023/05/30 14:44:56 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	terminate_texture(t_texture_images *texture_pouinter);

void	error_free_texture(t_texture_images *textures_pointers, mlx_t *mlx)
{
	terminate_texture(textures_pointers);
	exit(1);
}

mlx_image_t	*make_and_display_texture(t_coordinate	*cell_codinates,
	mlx_texture_t *texture, int size, mlx_t **mlx)
{
	mlx_image_t	*images;
	bool		success;

	images = mlx_texture_to_image(*mlx, texture);
	if (!images)
		return (NULL);
	if (!mlx_resize_image(images, size, size))
		return (NULL);
	if (mlx_image_to_window(*mlx, images,
			cell_codinates->x * size, cell_codinates->y * size) < 0)
		return (NULL);
	return (images);
}

void	load_cell_p3(mlx_t **mlx, t_cell *cell,
			t_texture_images *textures_pointers,
			t_coordinate	*cell_codinates);
void	load_cell_p2(mlx_t **mlx, t_cell *cell,
			t_texture_images *textures_pointers,
			t_coordinate	*cell_codinates);

// load a single cell of the map 
// @param cell put the pointer of images made in here
void	load_cell(mlx_t **mlx, t_cell *cell,
	t_texture_images *textures_pointers, t_coordinate	*cell_codinates)
{
	int	size;

	size = 16;
	if ((*cell).type == '1')
	{
		(*cell).background = make_and_display_texture(cell_codinates,
				textures_pointers->wall, size, mlx);
		if ((*cell).background == NULL)
			error_free_texture(textures_pointers, *mlx);
		(*cell).object = NULL;
		(*cell).player = NULL;
		return ;
	}
	(*cell).background = make_and_display_texture(cell_codinates,
			textures_pointers->background, size, mlx);
	if ((*cell).background == NULL)
		error_free_texture(textures_pointers, *mlx);
	load_cell_p2(mlx, cell, textures_pointers, cell_codinates);
}

void	load_cell_p2(mlx_t **mlx, t_cell *cell,
	t_texture_images *textures_pointers, t_coordinate	*cell_codinates)
{
	int	size;

	size = 16;
	if ((*cell).type == 'C')
	{
		(*cell).object = make_and_display_texture(cell_codinates,
				textures_pointers->item, size, mlx);
		if ((*cell).object == NULL)
			error_free_texture(textures_pointers, *mlx);
		(*cell).player = NULL;
	}
	if ((*cell).type == 'E')
	{
		(*cell).object = make_and_display_texture(cell_codinates,
				textures_pointers->exit, size, mlx);
		if ((*cell).object == NULL)
			error_free_texture(textures_pointers, *mlx);
		(*cell).player = NULL;
	}
	load_cell_p3(mlx, cell, textures_pointers, cell_codinates);
}

void	load_cell_p3(mlx_t **mlx, t_cell *cell,
	t_texture_images *textures_pointers, t_coordinate	*cell_codinates)
{
	int	size;

	size = 16;
	if ((*cell).has_player)
	{
		(*cell).player = make_and_display_texture(cell_codinates,
				textures_pointers->player_front, size, mlx);
		if ((*cell).player == NULL)
			error_free_texture(textures_pointers, *mlx);
		(*cell).object = NULL;
	}
}
