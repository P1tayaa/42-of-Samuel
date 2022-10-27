/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:17:11 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/27 23:07:14 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int	ft_atoi_base_take_care_of_neg(int *number, int *numer_of_char_print)
{
	if (ft_putchar('-') == -1)
		return (-1);
	*number = -*number;
	*numer_of_char_print = *numer_of_char_print + 1;
	return (1);
}

int	ft_itoa_base(int number, int base, int isfirst, char lettle)
{
	int	numer_of_char_print;
	int	temp_num;

	numer_of_char_print = 0;
	if (-2147483648 == number && base == 10)
		return (ft_putstr("-2147483648"));
	if (number < 0)
		if (ft_atoi_base_take_care_of_neg(&number, &numer_of_char_print) == -1)
			return (-1);
	if (number != 0 || isfirst == 1)
	{
		temp_num = ft_itoa_base(number / base, base, 0, lettle);
		if (temp_num == -1)
			return (-1);
		numer_of_char_print = numer_of_char_print + temp_num;
		if ((number % base) < 10)
			if (ft_putchar((number % base) + '0') == -1)
				return (-1);
		if ((number % base) > 9)
			if (ft_putchar((number % base) + lettle - 10) == -1)
				return (-1);
	}
	if (isfirst)
		numer_of_char_print--;
	return (numer_of_char_print + 1);
}

int	ft_atoui_base(unsigned int number, unsigned int base,
	int isfirst, char lettle)
{	
	int	numer_of_char_print;

	numer_of_char_print = 0;
	if (number != 0 || isfirst == 1)
	{
		numer_of_char_print = ft_atoui_base(number / base, base, 0, lettle);
		if (numer_of_char_print == -1)
			return (-1);
		if ((number % base) < 10)
			if (ft_putchar((number % base) + '0') == -1)
				return (-1);
		if ((number % base) > 9)
			if (ft_putchar((number % base) + lettle - 10) == -1)
				return (-1);
	}
	if (isfirst)
		numer_of_char_print--;
	return (numer_of_char_print + 1);
}

int	ft_atoull_base(unsigned long long number, unsigned long long base,
	int isfirst, char lettle)
{	
	int	numer_of_char_print;

	if (isfirst == 1)
		if (ft_putstr("0x") == -1)
			return (-1);
	numer_of_char_print = 0;
	if (number != 0 || isfirst == 1)
	{
		numer_of_char_print = ft_atoull_base(number / base, base, 0, lettle);
		if (numer_of_char_print == -1)
			return (-1);
		if ((number % base) < 10)
			if (ft_putchar((number % base) + '0') == -1)
				return (-1);
		if ((number % base) > 9)
			if (ft_putchar((number % base) + lettle - 10) == -1)
				return (-1);
	}
	if (isfirst)
		numer_of_char_print++;
	return (numer_of_char_print + 1);
}

int	manage_print(char const *input, size_t *i, va_list arg)
{
	int		numer_of_char_print;
	char	*string;

	*i = *i + 1;
	numer_of_char_print = 0;
	if (input[*i] == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (input[*i] == 's')
	{
		string = va_arg(arg, char *);
		if (string == NULL)
			string = "(null)";
		return (ft_putstr(string));
	}
	if (input[*i] == 'p')
		return (ft_atoull_base(va_arg(arg,
					unsigned long long), 16, 1, 'a'));
	if (input[*i] == 'i' || input[*i] == 'd')
		return (ft_itoa_base(va_arg(arg, int), 10, 1, 'A'));
	if (input[*i] == 'u')
		return (ft_atoui_base(va_arg(arg, unsigned int), 10, 1, 'A'));
	if (input[*i] == 'X' || input[*i] == 'x')
		return (ft_atoui_base(va_arg(arg, int), 16, 1, input[*i] - 23));
	return (-1);
}
