/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:36:55 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/14 18:05:08 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char const *s, char c)
{
	size_t			i;
	unsigned int	number_of_string;
	unsigned int	size_count;
	char			**array_string;

	i = 0;
	number_of_string = 0;
	while(s[i] != '\0')
	{
		if (i == 0 && s[i] == c)
			while(s[i] == c)
				i++;
		if(s[i] == c && s[i + 1] != c)
			number_of_string++;
		i++;
	}
	if (number_of_string == 0 && s[i] == c)
		return NULL;
	else
	{
		array_string = (char **)malloc(number_of_string * sizeof(char *));
		if (!array_string)
			return (NULL);
	}
	number_of_string = 0;
	size_count = 0;
	i = 0;
	while(s[i] != '\0')
	{
		if (i == 0 && s[i] == c)
			while(s[i] == c)
				i++;
		if(s[i] != c)
			size_count++;
		if(s[i] == c && s[i + 1] != c)
		{
			array_string[number_of_string] = (char *)malloc((size_count + 1) * sizeof(char));
			number_of_string++;
			size_count = 0;
		}
		i++;
	}
	if (s[i - 1] != c && i != 0)
		array_string[number_of_string] = (char *)malloc((size_count + 1) * sizeof(char));
	number_of_string = 0;
	size_count = 0;
	i = 0;
	while(s[i] != '\0')
	{
		if (i == 0 && s[i] == c)
			while(s[i] == c)
				i++;
		if(s[i] != c)
		{
			array_string[number_of_string][size_count] = s[i];
			size_count++;
		}
		if(s[i] == c && s[i + 1] != c)
		{
			array_string[number_of_string][size_count] = '\0';
			number_of_string++;
			size_count = 0;
		}
		i++;
	}
	if (s[i - 1] != c && i != 0)
		array_string[number_of_string][size_count] = '\0';
	return (array_string);
}

// int	main(void)
// {
// 	char	**strs;
// 	char	*str;
// 	char	charslip;
// 	int		i;

// 	str = " split";
// 	strs = ft_split(str, ' ');
// 	i = 0;
// 	ft_putstr("start\n\n");
// 	while (i < 1)
// 	{
// 		ft_putstr(strs[i]);
// 		ft_putstr("\n");
// 		i++;
// 	}
// 	i = 0;
// 	while(i < 1)
// 	{
// 		free(strs[i]);
// 		i++;
// 	}
// 	// free(strs);
// }
