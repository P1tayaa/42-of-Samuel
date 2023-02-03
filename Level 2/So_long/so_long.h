/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:48:20 by sboulain          #+#    #+#             */
/*   Updated: 2023/02/03 20:43:05 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mega_libft/libft.h"
#include "mlx/mlx.h"
//for close
#include <unistd.h>
//for math function
#include <math.h>
//for open
#include <fcntl.h>
//for bool
#include <stdbool.h>
//for malloc and free
#include <stdlib.h>

typedef struct
{
	bool	play_can_access;
	bool	has_player;
	bool	has_enemy;
	char	type;

}	t_cell;