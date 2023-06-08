/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:42:45 by sboulain          #+#    #+#             */
/*   Updated: 2023/06/08 19:33:30 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//for write
# include <unistd.h>
//for bool
# include <stdbool.h>

#include <stdlib.h>

char	*strdup(const char *s)
{
	char	*dupstr;
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	dupstr = (char *)malloc((i + 1) * sizeof(char));
	if (!dupstr)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dupstr[i] = s[i];
		i++;
	}
	dupstr[i] = '\0';
	return (dupstr);
}

void	string_rev(char *str)
{
	int len;
	int	i;
	char temp;

	len = 0;
	while (str[len]!= '\0')
		len++;
	i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
		i++;
	}
}

char	*itoa(int num)
{
	char	*str[13];
	int		i;
	bool	is_neg;

	if (num == -2147483648)
		return ("-2147483648");
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
	if (is_neg)
		str[i++] = '-';
	str[i] = '\0';
	return (string_rev(str), str);
}


char	*put_num_64(uint64_t num)
{
	char	str[20];
	int		i;
	
	if (num == 0)
		str[0] = '0';
	i = 0;
	while (num != 0)
	{
		str[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	str[i] = '\0';
	string_rev(str);
	return (str);
}

bool	ft_atoi(char *str, int *number)
{
	int		i;
	long	number_long;
	bool	is_neg;
	
	i = 0;
	is_neg = false;
	if (str[i] == '-')
	{
		is_neg = true;
		i++;
	}
	number_long = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' &&  str[i] <= '9'))
			return (false);
		number_long = (number_long * 10) + (str[i] - '0');
		if ((number_long > 2147483647 && !is_neg) || (number_long > 2147483648 && is_neg))
			return (false);
		i++;
	}
	
	*number = (int)number_long;
	return (true);
}


char	*str_join_and_free(char *str1, char *str2)
{
	char *new_str;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str1[i]!= '\0')
		i++;
	while (str2[j]!= '\0')
		j++;
	new_str = malloc(sizeof(char) * (i + j + 1));
	i = 0;
	while (str1[i]!= '\0')
	{
		new_str[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j]!= '\0')
	{
		new_str[i + j] = str2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (free(str1), free(str2), new_str);
}
