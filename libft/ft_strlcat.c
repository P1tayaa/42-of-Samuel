/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:51:25 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/08 18:18:48 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char * dst, const char * src, size_t dstsize)
{
	char *dstend;

	dstend = &dst[ft_strlen(dst)];
	return (ft_strlcpy(dstend, src, dstsize - ft_strlen(dst)));
}
