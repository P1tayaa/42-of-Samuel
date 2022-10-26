/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:34:27 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/26 18:44:37 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_atoi_base(int number, int base, int isfirst, char lettle)
{
	int	numer_of_char_print;
	
	numer_of_char_print = 0;
	if (-2147483648 == number && base == 10)
	{
		ft_putstr("-2147483648");
		return (12);
	}
	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
		numer_of_char_print++;
	}
	if (number != 0 || isfirst == 1)
	{
		numer_of_char_print = numer_of_char_print + ft_atoi_base(number / base, base, 0, lettle);
		if ((number % base) < 10)
			ft_putchar((number % base) + '0');
		if ((number % base) > 9)
			ft_putchar((number % base) + lettle - 10);
	}
	return (numer_of_char_print + 1);
}

int	ft_atoui_base(unsigned int number, unsigned int base, int isfirst, char lettle)
{	
	int	numer_of_char_print;
	
	numer_of_char_print = 0;
	
	if (number != 0 || isfirst == 1)
	{
		numer_of_char_print = ft_atoi_base(number / base, base, 0, lettle);
		if ((number % base) < 10)
			ft_putchar((number % base) + '0');
		if ((number % base) > 9)
			ft_putchar((number % base) + lettle - 10);
	}
	return (numer_of_char_print + 1);
}
int	ft_atoull_base(unsigned long long number, unsigned long long base, int isfirst, char lettle)
{	
	int	numer_of_char_print;
	
	numer_of_char_print = 0;
	
	if (number != 0 || isfirst == 1)
	{
		numer_of_char_print = ft_atoull_base(number / base, base, 0, lettle);
		if ((number % base) < 10)
			ft_putchar((number % base) + '0');
		if ((number % base) > 9)
			ft_putchar((number % base) + lettle - 10);
	}
	return (numer_of_char_print + 1);
}

int	manage_print(char const *input, size_t i, va_list arg)
{
	int		numer_of_char_print;
	char	*string;
	
	numer_of_char_print = 0;
	if (input[i] == 'c')
		ft_putchar(va_arg(arg, int));
	if (input[i] == 's')
	{
		string = va_arg(arg, char *);
		if (string == NULL)
		{
			ft_putstr("(null)");
			return (6);
		}
		ft_putstr(string);
		return (ft_strlen(string));
	}
	if (input[i] == 'p')
	{
		ft_putstr("0x");
		return (ft_atoull_base(va_arg(arg, unsigned long long), 16, 1, 'a') + 1);
	}
	if (input[i] == 'i' || input[i] == 'd')
		return (ft_atoi_base(va_arg(arg,  int), 10, 1, 'A') - 1);
	if (input[i] == 'u')
		return (ft_atoui_base(va_arg(arg, unsigned int), 10, 1, 'A') - 1);
	if (input[i] == 'X' || input[i] == 'x')
		return (ft_atoui_base(va_arg(arg, int), 16, 1, input[i] - 23) - 1);
	return (1);
}

int get_purcentage_signs(char const *input, va_list arg)
{
	size_t	i;
	int		number_of_purcentage;
	int		numer_of_char_print;

	i = 0;
	numer_of_char_print = 0;
	number_of_purcentage = 0;
	while (input[i] != '\0')
	{
		if(input[i] == '%' && input[i + 1] == '%')
		{
			ft_putchar('%');
			i++;
			number_of_purcentage++;
			numer_of_char_print++;
		}
		else if (input[i] == '%')
		{
			i++;
			numer_of_char_print = numer_of_char_print + manage_print(input, i, arg);
		}
		else
		{
			ft_putchar(input[i]);
			numer_of_char_print++;
		}
		i++;
	}
	return (numer_of_char_print);
}

int	ft_printf(const char *input, ...)
{
	int	numer_of_char_print;

	va_list arg;
	va_start(arg, input);
	numer_of_char_print = get_purcentage_signs(input, arg);
	va_end(arg);
	return (numer_of_char_print);
}

// int main(void)
// {
// 	int p = 568487;
// 	void *pp = &p;
// 	ft_printf("1234%%__%u\n", p);
// 	printf("1234%%__%u\n", p);
// }