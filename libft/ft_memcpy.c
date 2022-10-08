/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:30:22 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/08 19:20:52 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t	i;
	
	if(dst)
	{
		i = 0;
		while (i < n)
		{
			*(char *) (dst + i) =  *(char *) (src + i);
			i++;
		}
	}
	return (dst);
}
