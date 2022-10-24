/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:51:25 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/10 21:15:49 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*dstend;
	size_t	length_of_dst;

	dstend = &dst[ft_strlen(dst)];
	length_of_dst = ft_strlen(dst);
	if (dstsize > length_of_dst)
		ft_strlcpy(dstend, src, dstsize - length_of_dst);
	if (length_of_dst < dstsize)
		return (length_of_dst + ft_strlen(src));
	return (dstsize + ft_strlen(src));
}
