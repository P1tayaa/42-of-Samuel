/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:55:40 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/06 11:18:40 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *str)
{
	int	number;
	int	i;

	i = 0;
	number = 0;
	if (str[0] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i] != '\0')
	{
		number = (number) * 10 + (str[i] - '0');
		i++;
	}
	if (str[0] == '-')
		number = number * -1;
	return (number);
}
