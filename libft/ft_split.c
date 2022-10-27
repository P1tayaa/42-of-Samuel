/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:36:55 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/27 12:49:49 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	**malloc_error_free(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

unsigned int	get_work_count(char const *s, char c)
{
	size_t			i;
	unsigned int	number_of_words;
	int				has_space;

	number_of_words = 0;
	has_space = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			number_of_words++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		number_of_words++;
	return (number_of_words);
}

size_t	index_end_word(char const *s, char c, size_t i)
{
	size_t	starting_i;

	starting_i = i;
	while (s[i])
	{
		if (s[i] == c)
			return (i - starting_i);
		i++;
	}
	return (i - starting_i);
}

void	do_stuff(unsigned int *size_count, char const *s, char *c, size_t *i)
{
	while (s[*i] != *c && s[*i])
				*i = *i + 1;
		*size_count = *size_count + 1;
}

char	**ft_split(char const *s, char c)
{
	char			**array_string;
	unsigned int	size_c;
	size_t			i;

	if (!s)
		return (NULL);
	array_string = (char **)malloc((get_work_count(s, c) + 1) * sizeof(char *));
	if (!array_string)
		return (NULL);
	i = 0;
	size_c = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		array_string[size_c] = (char *)malloc(index_end_word(s, c, i) + 1);
		if (!array_string[size_c])
			return (malloc_error_free(array_string));
		ft_strlcpy(array_string[size_c], &s[i], index_end_word(s, c, i) + 1);
		do_stuff(&size_c, s, &c, &i);
	}
	array_string[size_c] = NULL;
	return (array_string);
}

// int	main(void)
// {
// 	char	**strs;
// 	// char	*str;
// 	size_t		i;

// 	i = 0;
// 	// ft_putnbr((int)index_end_word
// 	("I am a potatomaster numero eno", 32, &i));
// 	// str = " split";
// 	strs = ft_split("afo haoh aeoh ae fo       f ffaff aegi ", 32);
// 	i = 0;

// 	while (i < 8)
// 	{
// 		ft_putstr(strs[i]);
// 		ft_putstr("\n");
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 8)
// 	{
// 		free(strs[i]);
// 		i++;
// 	}
// 	free(strs);
// 	system("leaks a.out");	
// 	return (0);
// }