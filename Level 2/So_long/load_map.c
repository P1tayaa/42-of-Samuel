/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:43:36 by sboulain          #+#    #+#             */
/*   Updated: 2023/06/02 14:49:47 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_source_images	*create_path_png(void);

void			path_image_free(t_source_images *images_source);

// make the list of texture with the path of png sprites
t_texture_images	*make_texture_from_png(t_source_images *images_source)
{
	t_texture_images	*images_to_texture;

	images_to_texture = malloc(sizeof(t_texture_images));
	if (!images_to_texture)
		exit(1);
	images_to_texture->background = mlx_load_png(images_source->background);
	images_to_texture->wall = mlx_load_png(images_source->wall);
	images_to_texture->item = mlx_load_png(images_source->item);
	images_to_texture->exit = mlx_load_png(images_source->exit);
	images_to_texture->player_front = mlx_load_png(images_source->player_front);
	images_to_texture->player_left = mlx_load_png(images_source->player_left);
	images_to_texture->player_right = mlx_load_png(images_source->player_right);
	images_to_texture->player_back = mlx_load_png(images_source->player_back);
	if (!images_to_texture->background || !images_to_texture->wall
		|| !images_to_texture->item
		|| !images_to_texture->exit || !images_to_texture->player_front
		|| !images_to_texture->player_left || !images_to_texture->player_right
		|| !images_to_texture->player_back)
		exit(1);
	return (images_to_texture);
}

// free the list of textures (mlx ones)
void	terminate_texture(t_texture_images *texture_pouinter)
{
	mlx_delete_texture(texture_pouinter->background);
	mlx_delete_texture(texture_pouinter->wall);
	mlx_delete_texture(texture_pouinter->item);
	mlx_delete_texture(texture_pouinter->exit);
	mlx_delete_texture(texture_pouinter->player_front);
	mlx_delete_texture(texture_pouinter->player_left);
	mlx_delete_texture(texture_pouinter->player_right);
	mlx_delete_texture(texture_pouinter->player_back);
	free(texture_pouinter);
	texture_pouinter = NULL;
}

void			load_cell(mlx_t **mlx, t_cell *cell,
					t_texture_images *textures_pointers,
					t_coordinate	*cell_codinates);

void	load_map_images(mlx_t **mlx, t_map **map,
	t_texture_images *textures_pointers)
{
	int				i;
	int				j;
	t_coordinate	*cell_codinates;

	cell_codinates = malloc(sizeof(t_coordinate));
	if (!cell_codinates)
		exit(1);
	i = 0;
	while (i <= (*map)->max_index_y_down)
	{
		j = 0;
		while (j <= (*map)->max_index_x_right)
		{
			cell_codinates->y = i;
			cell_codinates->x = j;
			load_cell(mlx, &((*map)->cells[i][j]),
				textures_pointers, cell_codinates);
			j++;
		}
		i++;
	}
	free(cell_codinates);
}

// mlx_image_t	***load_images_map(t_map *map, )
// {
// 	mlx_image_t	***map_of_images;

// }

t_texture_images	*load_images(void)
{
	t_source_images		*images_source;
	t_texture_images	*textures_pointers;
	t_image_images		*images_pointers;

	images_source = create_path_png();
	textures_pointers = make_texture_from_png(images_source);
	path_image_free(images_source);
	images_pointers = NULL;
	return (textures_pointers);
}

t_texture_images	*load_map(mlx_t **mlx, t_map **map)
{
	t_texture_images	*textures_pointers;

	textures_pointers = load_images();
	load_map_images(mlx, map, textures_pointers);
	return (textures_pointers);
}
