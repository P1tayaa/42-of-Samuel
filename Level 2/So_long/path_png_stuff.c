/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_png_stuff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:25:09 by sboulain          #+#    #+#             */
/*   Updated: 2023/05/29 20:25:23 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

// free the struct and deffines all the location of the images/sprites
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
