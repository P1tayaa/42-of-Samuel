/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:27:38 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/10 21:13:03 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*str;

	size = ft_strlen(s1) + ft_strlen(s2);
	if (size == 0)
	{
		str = ft_strnew(1);
		return (str);
	}
	str = ft_strnew(size);
	if (!str)
		return (NULL);
	ft_memmove(str, s1, ft_strlen(s1));
	ft_memmove(&str[ft_strlen(s1)], s2, ft_strlen(s2));
	return (str);
}