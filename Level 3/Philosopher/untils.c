/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:42:45 by sboulain          #+#    #+#             */
/*   Updated: 2023/02/18 19:50:03 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//for write
# include <unistd.h>
//for bool
# include <stdbool.h>

void	put_num(int num)
{
	char	str[13];
	int		i;
	bool	is_neg;


	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	is_neg = false;
	if (num < 0)
	{
		is_neg = true;
		num = -num;
	}
	i = 0;
	while (num != 0)
	{
		str[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	str[i] = '\0';
	if (is_neg)
		write(1, "-",1);
	while (i != -1)
	{
		write(1, &(str[i]), 1);
		i--;
	}
}

bool	ft_atoi(char *str, int *number)
{
	int		i;
	long	number_long;
	bool	is_neg;
	
	i = 0;
	is_neg = false;
	if (str[i])
	{
		is_neg = true;
		i++;
	}
	number_long = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' &&  str[i] > '9')
			return (false);
		number_long = (number_long * 10) + (str[i] + '0');
		if ((number_long > 2147483647 && !is_neg) || (number_long > 2147483648 && is_neg))
		return (false);
		i++;
	}
	*number = (int)number_long;
	return (true);
}
