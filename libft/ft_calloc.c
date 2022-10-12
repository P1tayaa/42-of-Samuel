/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:27:25 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/12 16:23:44 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory_alocated;

	memory_alocated = (void *)malloc(count * size);
	if (!memory_alocated)
		return (NULL);
	ft_bzero(memory_alocated, count * size);
	return (memory_alocated);
}
