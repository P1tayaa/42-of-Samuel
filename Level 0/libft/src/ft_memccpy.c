/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:46:43 by sboulain          #+#    #+#             */
/*   Updated: 2024/07/04 13:36:54 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
		if (*(char *)(src + i - 1) == c)
		{
			
			return (&(((char *)dest)[i]));
		}
		n--;
	}
	return (0);
}
