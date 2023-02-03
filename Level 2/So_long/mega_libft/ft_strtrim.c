/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:30:56 by sboulain          #+#    #+#             */
/*   Updated: 2022/11/02 17:54:57 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static size_t	front_count(char const *s1,	char const *set, int did_find_front)
{
	unsigned long	i;
	unsigned long	j;
	size_t			front_remove;

	i = 0;
	front_remove = 0;
	while (i < ft_strlen(s1))
	{
		j = 0;
		while (j < ft_strlen(set))
		{
			if (s1[i] == set[j])
			{
				front_remove++;
				did_find_front++;
			}
			j++;
		}
		if (did_find_front == 0)
			break ;
		did_find_front = 0;
		i++;
	}
	return (front_remove);
}

static size_t	back_count(char const *s1, char const *set, int did_find_back)
{
	unsigned long	j;
	unsigned long	i;
	size_t			back_remove;

	back_remove = 0;
	i = ft_strlen(s1) - 1;
	while (i < ft_strlen(s1))
	{
		j = 0;
		while (j < ft_strlen(set))
		{
			if (s1[i] == set[j])
			{
				back_remove++;
				did_find_back++;
			}
			j++;
		}
		if (did_find_back == 0)
			break ;
		did_find_back = 0;
		i--;
	}
	return (back_remove);
}

static char	*copy_to_string(char *str, char const *s1,
	unsigned long i, size_t back_remove)
{
	unsigned int	j;

	j = 0;
	while (i < ft_strlen(s1) - back_remove)
	{
		str[j] = s1[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned long	i;
	size_t			front_remove;
	size_t			back_remove;

	if (!s1)
		return (NULL);
	if (!set || set[0] == '\0')
		return (ft_strdup(s1));
	if (s1[0] == '\0' && set[0] == '\0')
		return (ft_strdup("\0"));
	front_remove = front_count(s1, set, 0);
	back_remove = back_count(s1, set, 0);
	if (front_remove == ft_strlen(s1))
		return (ft_strdup("\0"));
	str = ft_calloc(ft_strlen(s1) - front_remove - back_remove + 1, 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i != (unsigned long) front_remove)
		i++;
	return (copy_to_string(str, s1, i, back_remove));
}

// int main(void)
// {
// 	char str1[] = "";
// 	char set[] = "";
// 	char *str2;

// 	str2 = ft_strtrim(" . abcd", " ");
// 	printf("%s\n", str2);
// 	free (str2);
// }
