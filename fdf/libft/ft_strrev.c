/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:29:18 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/28 18:13:50 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	j;
	char	temp;

	j = ft_strlen(str);
	i = 0;
	while (j - i > 1)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--:
		}
			return (str);
	}
