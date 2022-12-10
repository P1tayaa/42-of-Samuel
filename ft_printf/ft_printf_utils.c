/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:17:11 by sboulain          #+#    #+#             */
/*   Updated: 2022/12/08 16:30:51 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stddef.h>

int	ft_atoi_base_take_care_of_neg(int *number, int *numer_of_char_print)
{
	if (ft_putchar_int('-') == -1)
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
		return (ft_putstr_int("-2147483648"));
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
			if (ft_putchar_int((number % base) + '0') == -1)
				return (-1);
		if ((number % base) > 9)
			if (ft_putchar_int((number % base) + lettle - 10) == -1)
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
			if (ft_putchar_int((number % base) + '0') == -1)
				return (-1);
		if ((number % base) > 9)
			if (ft_putchar_int((number % base) + lettle - 10) == -1)
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
		if (ft_putstr_int("0x") == -1)
			return (-1);
	numer_of_char_print = 0;
	if (number != 0 || isfirst == 1)
	{
		numer_of_char_print = ft_atoull_base(number / base, base, 0, lettle);
		if (numer_of_char_print == -1)
			return (-1);
		if ((number % base) < 10)
			if (ft_putchar_int((number % base) + '0') == -1)
				return (-1);
		if ((number % base) > 9)
			if (ft_putchar_int((number % base) + lettle - 10) == -1)
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

	*i = *i + 2;
	numer_of_char_print = 0;
	if (input[*i - 1] == 'c')
		return (ft_putchar_int(va_arg(arg, int)));
	if (input[*i - 1] == 's')
	{
		string = va_arg(arg, char *);
		if (string == NULL)
			string = "(null)";
		return (ft_putstr_int(string));
	}
	if (input[*i - 1] == 'p')
		return (ft_atoull_base(va_arg(arg,
					unsigned long long), 16, 1, 'a'));
	if (input[*i - 1] == 'i' || input[*i - 1] == 'd')
		return (ft_itoa_base(va_arg(arg, int), 10, 1, 'A'));
	if (input[*i - 1] == 'u')
		return (ft_atoui_base(va_arg(arg, unsigned int), 10, 1, 'A'));
	if (input[*i - 1] == 'X' || input[*i - 1] == 'x')
		return (ft_atoui_base(va_arg(arg, int), 16, 1, input[*i - 1] - 23));
	return (-1);
}
