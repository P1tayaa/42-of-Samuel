/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 19:23:21 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/10 13:39:38 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char    *ft_strrev_skip1(char * str, int isneg)
{
	int     i;
	int     j;
	char    temp;

	i = 0;
	if (isneg == 1)
		i = 1;
	j = ft_strlen(str) - 1;
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

int how_many_char(int n)
{
	int i;

	if(n == 0)
		return (1);
	i = 0;
	while(n != 0)
	{
		n = n / 10;
		i++;
	}
	if (i > 10)
		i = 10;
	return (i);
}

char    *ft_itoa(int n)
{
	char    *number;
	int     i;
	int     isneg;

	i = 0;
	isneg = 0;
	if (n < 0)
	{
		n = -n;
		isneg++;
		i++;
	}
	if (n == -2147483648)
	{
		number = (char *)malloc(12 * sizeof(char));
		if (!number)
			return (NULL);
		number [0] = '-';
		number [1] = '2';
		number [2] = '1';
		number [3] = '4';
		number [4] = '7';
		number [5] = '4';
		number [6] = '8';
		number [7] = '3';
		number [8] = '6';
		number [9] = '4';
		number [10] = '8';
		number [11] = '\0';
		return (number);
	}
	number = (char *)malloc((isneg + how_many_char(n)  + 1) * sizeof(char));
	if (!number)
		return (NULL);
	if (n == 0)
	{
		number[i] = '0';
		i++;
	}
	if(isneg)
		number[0] = '-';
	while(n != 0)
	{
		number[i] = '0' + (n % 10);
		n = n / 10;
		i++;
	}
	number[i] = '\0';
	return (ft_strrev_skip1(number, isneg));
}
