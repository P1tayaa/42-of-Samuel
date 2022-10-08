/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 19:23:21 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/08 20:44:56 by sboulain         ###   ########.fr       */
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

	i = 0;
	while(n != 0)
	{
		n = n / 10;
		i++;
	}
	ft_putstr("number of char : ");
	ft_putnbr(i);
	return (i);
}

char    *ft_itoa(int n)
{
	char    *number;
	int     i;
	int     isneg;

	i = 0;
	isneg = how_many_char(n);
	if (n < 0)
	{
		n = -n;
		isneg++;
		i++;
	}
	number = (char *)malloc(isneg * sizeof(char));
	if (!number)
		return (NULL);
	if (n == -2147483648)
	{
		number = "-2147483648";
		return (number);
	}
	if (n == 0)
		number[i] = '0';
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
