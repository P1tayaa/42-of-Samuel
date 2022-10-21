/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:34:27 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/21 23:08:35 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

// int	main(void)
// {
// 	printf("%'d", -2147483647);
// }

int get_purcentage_signs(char *input, int *which_indext, char *which_type)
{
	size_t	i;
	int		number_of_purcentage;

	i = 0;
	number_of_purcentage = 0;
	while (input[i] != '\0')
	{
		if(input[i] == '%' && input[i + 1] == '%')
		{
			number_of_purcentage++;
		}
		i++;
	}
	// which
	return (0);
	
}

void ft_atoi_base(int number, int base, int isfirst, char lettle)
{
	char	to_print;
	
	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
	}
	if (number != 0 || isfirst == 1)
	{
		ft_atoi_base(number / base, base, 0, lettle);
		if ((number % base) < 10)
			to_print = (number % base) + '0';
		if ((number % base) > 9)
			to_print = (number % base) + lettle - 10;
		write(1, &to_print, 1);
	}
}



int main(void)
{
	ft_atoi_base(1005, 16, 1, 'a');
}
