/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:51:25 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/06 13:54:13 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	strlcat(char * restrict dst, const char * restrict src, size_t dstsize)
{
	ft_strlcpy(&dst[ft_strlen(dst)], src, dstsize - ft_strlen(dst))
	return (dstsize);
}