/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:59:11 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/06 13:34:13 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	if (!dst || !src)
		return (NULL);
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			*((char *)(dst + i)) = *((char *)(src + i));
			i++;
		}
	}
	else
	{
		i = len;
		while (i != -1)
		{
			*((char *)(dst + i)) = *((char *)(src + i));
			i--;
		}
	}
	return (dst);
}
