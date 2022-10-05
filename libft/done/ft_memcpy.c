/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:30:22 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/05 19:12:32 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
    int		i;
	
	i = 0;
	while (n != 0)
	{
		*(char *) (dst + i) =  *(char *) (src + i);
		i++;
		n--;
	}
	return (dst);
}




