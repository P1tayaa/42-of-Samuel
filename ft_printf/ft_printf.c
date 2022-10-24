/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:34:27 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/24 20:00:30 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>



// int	main(void)
// {
// 	printf("%'d", -2147483647);
// }

void ft_atoi_base(int number, int base, int isfirst, char lettle)
{
	
	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
	}
	if (number != 0 || isfirst == 1)
	{
		ft_atoi_base(number / base, base, 0, lettle);
		if ((number % base) < 10)
			ft_putchar((number % base) + '0');
		if ((number % base) > 9)
			ft_putchar((number % base) + lettle - 10);
	}
}

void ft_atoui_base(unsigned int number, unsigned int base, int isfirst, char lettle)
{	
	if (number != 0 || isfirst == 1)
	{
		ft_atoi_base(number / base, base, 0, lettle);
		if ((number % base) < 10)
			ft_putchar((number % base) + '0');
		if ((number % base) > 9)
			ft_putchar((number % base) + lettle - 10);
	}
}

void	manage_print(char const *input, size_t i, va_list arg)
{
	if (input[i] == 'c')
		ft_putchar(va_arg(arg, int));
	if (input[i] == 's')
		ft_putstr(va_arg(arg, char *));
	if (input[i] == 'p')
	{
		ft_putstr("0x7ffe");
		ft_atoui_base(va_arg(arg, unsigned int), 16, 1, 'a');
	}
	if (input[i] == 'i' || input[i] == 'd')
		ft_atoi_base(va_arg(arg,  int), 10, 1, 'A');
	if (input[i] == 'u')
		ft_atoui_base(va_arg(arg, unsigned int), 10, 1, 'A');
	if (input[i] == 'X' || input[i] == 'x')
		ft_atoi_base(va_arg(arg, int), 16, 1, input[i] - 29);
}

int get_purcentage_signs(char const *input, va_list arg)
{
	size_t	i;
	int		number_of_purcentage;

	i = 0;
	number_of_purcentage = 0;
	while (input[i] != '\0')
	{
		if(input[i] == '%' && input[i + 1] == '%')
		{
			ft_putchar('%');
			i++;
			number_of_purcentage++;
		}
		else if (input[i] == '%')
		{
			i++;
			manage_print(input, i, arg);
		}
		else
			ft_putchar(input[i]);
		i++;
	}
	return (0);
}

int    ft_printf(const char *input, ...)
{
	va_list arg;
	va_start(arg, input);
	get_purcentage_signs(input, arg);
	va_end(arg);
	return (0);
}

// int main(void)
// {
// 	int p = 568487;
// 	void *pp = &p;
// 	ft_printf("1234%%__%u\n", p);
// 	printf("1234%%__%u\n", p);
// }
