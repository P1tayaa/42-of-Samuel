/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:43:36 by sboulain          #+#    #+#             */
/*   Updated: 2023/05/21 17:57:02 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error(void);

t_source_images	*create_path_images(void)
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
	images_source->player_back = ft_strdup("./textures/chracter_back.png");
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

t_texture_images	*make_texture_from_images(t_source_images *images_source)
{
	t_texture_images	*images_to_texture;

	images_to_texture = malloc(sizeof(t_texture_images));
	images_to_texture->background = mlx_load_png(images_source->background);
	images_to_texture->wall = mlx_load_png(images_source->wall);
	images_to_texture->item = mlx_load_png(images_source->item);
	images_to_texture->exit = mlx_load_png(images_source->exit);
	images_to_texture->player_front = mlx_load_png(images_source->player_front);
	images_to_texture->player_left = mlx_load_png(images_source->player_left);
	images_to_texture->player_right = mlx_load_png(images_source->player_right);
	images_to_texture->player_back = mlx_load_png(images_source->player_back);
	return (images_to_texture);
}

void	load_images(mlx_t **mlx)
{
	t_source_images		*images_source;
	t_texture_images	*images_to_texture;

	images_source = create_path_images();
	images_to_texture = make_texture_from_images(images_source);
	path_image_free(images_source);
	
	mlx_image_t* img = mlx_texture_to_image(*mlx, images_to_texture->wall);
	if (!img || (mlx_image_to_window(*mlx, img, 0, 0) < 0))
		error();
	
	
}

void	load_map(mlx_t **mlx)
{
	load_images(mlx);
}
