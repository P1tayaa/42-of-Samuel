/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:43:36 by sboulain          #+#    #+#             */
/*   Updated: 2023/05/28 20:21:41 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error(void);

t_source_images	*create_path_png(void)
{
	t_source_images	*images_source;

	images_source = malloc(sizeof(t_source_images));
	if (!images_source)
		exit (1);
	images_source->background = ft_strdup("./textures/background.png");
	images_source->wall = ft_strdup("./textures/wall.png");
	images_source->item = ft_strdup("./textures/item.png");
	images_source->exit = ft_strdup("./textures/exit.png");
	images_source->player_front = ft_strdup("./textures/character_front.png");
	images_source->player_left = ft_strdup("./textures/character_left.png");
	images_source->player_right = ft_strdup("./textures/character_right.png");
	images_source->player_back = ft_strdup("./textures/character_back.png");
	if (!images_source->background || !images_source->wall
		|| !images_source->item
		|| !images_source->exit || !images_source->player_front
		|| !images_source->player_left || !images_source->player_right
		|| !images_source->player_back)
		exit(1);
	return (images_source);
}

void	path_image_free(t_source_images *images_source)
{
	if (!images_source)
		return ;
	free(images_source->background);
	free(images_source->wall);
	free(images_source->item);
	free(images_source->exit);
	free(images_source->player_front);
	free(images_source->player_left);
	free(images_source->player_right);
	free(images_source->player_back);
	free(images_source);
}

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

t_image_images	*make_images_from_texture(mlx_t **mlx, t_texture_images *texture_source)
{
	t_image_images	*images_source;

	images_source = malloc(sizeof(t_image_images));
	if (!images_source)
		exit(1);
	images_source->background = mlx_texture_to_image(*mlx, texture_source->background);
	images_source->wall = mlx_texture_to_image(*mlx, texture_source->wall);
	images_source->item = mlx_texture_to_image(*mlx, texture_source->item);
	images_source->exit = mlx_texture_to_image(*mlx, texture_source->exit);
	images_source->player_front = mlx_texture_to_image(*mlx, texture_source->player_front);
	images_source->player_left = mlx_texture_to_image(*mlx, texture_source->player_left);
	images_source->player_right = mlx_texture_to_image(*mlx, texture_source->player_right);
	images_source->player_back = mlx_texture_to_image(*mlx, texture_source->player_back);
	return (images_source);
}

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


void	load_cell(mlx_t **mlx, t_cell **cell, t_texture_images *textures_pointers, t_coordinate	*cell_codinates)
{
	if ((*cell)->type == '1')
	{
		(*cell)->background = mlx_texture_to_image(*mlx, textures_pointers->wall);
		if (mlx_image_to_window(*mlx, (*cell)->background, cell_codinates->x, cell_codinates->y) < 0)
        	exit (1);
		(*cell)->object = NULL;
		(*cell)->player = NULL;
		return ;
	}
	(*cell)->background = mlx_texture_to_image(*mlx, textures_pointers->background);
		if (mlx_image_to_window(*mlx, (*cell)->background, cell_codinates->x, cell_codinates->y) < 0)
        	exit (1);
	if ((*cell)->type == 'C')
	{
		(*cell)->object = mlx_texture_to_image(*mlx, textures_pointers->item);
		if (mlx_image_to_window(*mlx, (*cell)->object, cell_codinates->x, cell_codinates->y) < 0)
        	exit (1);
		(*cell)->player = NULL;
	}
	if ((*cell)->type == 'E')
	{
		(*cell)->object = mlx_texture_to_image(*mlx, textures_pointers->exit);
		if (mlx_image_to_window(*mlx, (*cell)->object, cell_codinates->x, cell_codinates->y) < 0)
        	exit (1);
		(*cell)->player = NULL;
	}
	if ((*cell)->has_player)
	{
		(*cell)->player = mlx_texture_to_image(*mlx, textures_pointers->player_front);
		if (mlx_image_to_window(*mlx, (*cell)->player, cell_codinates->x, cell_codinates->y) < 0)
        	exit (1);
		(*cell)->object = NULL;
	}
}

void	load_images(mlx_t **mlx)
{
	t_source_images		*images_source;
	t_texture_images	*textures_pointers;
	t_image_images		*images_pointers;

	images_source = create_path_png();
	ft_printf("test\n");
	textures_pointers = make_texture_from_png(images_source);
	ft_printf("test\n");
	path_image_free(images_source);
	images_pointers = make_images_from_texture(mlx, textures_pointers);
	ft_printf("test\n");
	// terminate_texture(textures_pointers);
	int i;
	i = 0;
}

void	load_map_images(mlx_t **mlx, t_map **map, t_texture_images *textures_pointers)
{
	int				i;
	int				j;
	t_coordinate	*cell_codinates;

	cell_codinates = malloc(sizeof(t_coordinate));
	if (!cell_codinates)
		exit(1);
	i = 0;
	while (i < (*map)->max_index_y_down)
	{
		j = 0;
		while (j < (*map)->index_of_player_x)
		{
			cell_codinates->y = i;
			cell_codinates->x = j;
			load_cell(&((*map)->cells[i][j]), textures_pointers, j, i);
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

void	load_map(mlx_t **mlx, t_map **map)
{
	load_images(mlx);
}
