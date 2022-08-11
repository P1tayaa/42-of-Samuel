/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 19:23:21 by sboulain          #+#    #+#             */
/*   Updated: 2022/08/11 19:23:21 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char    *ft_strrev_skip1(char * str, int isneg)
{
	int     i;
	int     j;
	char    temp;

	if (isneg == 1)
		i = 1;
	if (isneg == 0)
		i = 0;
	j = ft_strlen(str);
	while (j - i > 0)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

char    *ft_itoa(int n)
{
	char    *number;
	int     i;
	int     isneg;

	number = (char *)malloc(12 * sizeof(char));
	i = 0;
	isneg = 0;
	if (n == -2147483648)
	{
		number = "-2147483648";
		return (number);
	}
	if (n < 0)
	{
		n = -n;
		number[0] = '-';
		isneg = 1;
		i++;
	}
	while(n != 0)
	{
		number[i] = '0' + (n % 10);
		n = n / 10;
		i++;
	}
	number[i] = '\0';
	return (ft_strrev_skip1(number, isneg));
}
