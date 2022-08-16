/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:36:55 by sboulain          #+#    #+#             */
/*   Updated: 2022/08/11 22:36:55 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char ** ft_strsplit(char const *s, char c)
{
	int i;
	char **array_string;
	int counter_of_c;
	int number_of_char;

	// if (s == NULL)
	// 	return (NULL);
	i = 0;
	counter_of_c = 0;
	while (s[i] != '\0')
	{
		if (((s[i] == c && s[i + 1] != c) || (s[i + 1] == '\0')) &&  i != 0)
			counter_of_c++;
		i++;
	}
	// ft_putstr("test");
	array_string = (char **)malloc(counter_of_c * sizeof(char *));
	i = 0;
	counter_of_c = 0;
	number_of_char = 0;
	while (s[i] != '\0')
	{
		if (s[i - 1] == c && s[i] == c)
			number_of_char = 0;
		else if (s[i] == c && s[i + 1] != c)
		{
			array_string[counter_of_c] = (char *)malloc(number_of_char * sizeof(char));
		}
		if (((s[i] == c && s[i + 1] != c) || (s[i + 1] == '\0')) &&  i != 0)
			counter_of_c++;
		number_of_char++;
		i++;
	}
	// ft_putstr("test");
	i = 0;
	counter_of_c = 0;
	number_of_char = 0;
	while (s[i + 1] != '\0')
	{
		
		// ft_putnbr(counter_of_c);
		// ft_putendl("");
		// ft_putnbr(i);
		// ft_putendl("");
		if ((s[i] == c && s[i + 1] != c) || (s[i + 1] == '\0'))
		{
			number_of_char = 0;
		}
		if (((s[i] == c && s[i + 1] != c) || (s[i + 1] == '\0')) &&  i != 0)
		{
			array_string[counter_of_c][number_of_char] = '\0';
			counter_of_c++;
		}
		if (s[i - 1] == c && s[i] == c)
		{
			number_of_char = 0;
		}
		if(s[i] != c)
		{
			ft_putnbr(number_of_char);
			array_string[counter_of_c][number_of_char] = s[i];
		}
		number_of_char++;
		i++;
	}
	// ft_putstr("test");

	i = 0;
	while (i != 7)
	{
		printf("%s\n", array_string[i]);
		i++;
	}

	return (array_string);
}
