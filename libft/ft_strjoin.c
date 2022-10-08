/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:27:38 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/08 20:39:41 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char * ft_strjoin(char const *s1, char const *s2)
{
	int size;
	char    *str;

	size = ft_strlen(s1) + ft_strlen(s2) - 2;
	str = ft_strnew(size);
	ft_strcpy(str, s1);
	ft_strcpy(&str[ft_strlen(s1)], s2);
	return (str);
}