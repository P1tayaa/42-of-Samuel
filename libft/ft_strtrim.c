/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:30:56 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/14 18:47:20 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char*	ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned long	i;
	unsigned long	j;
	int				didFindBack;
	int				didFindFront;
	size_t			frontRemove;
	size_t			backRemove;

	frontRemove = 0;
	backRemove = 0;
	i = 0;
	if (!s1)
		return(NULL);
	if (!set || set[0] == '\0')
		return(ft_strdup(s1));
	if (s1[0] == '\0' && set[0] == '\0')
	{
		return (ft_strdup(""));
	}
	while (i < ft_strlen(s1))
	{
		j = 0;
		while(j < ft_strlen(set))
		{
			if (s1[i] == set[j])
			{
				frontRemove++;
				didFindFront++;
			}
			j++;
		}
		if (didFindFront == 0)
			break ;
		didFindFront = 0;
		i++;
	}
	i = ft_strlen(s1) - 1;
	while (i < ft_strlen(s1))
	{
		j = 0;
		while (j < ft_strlen(set))
		{
			if (s1[i] == set[j])
			{
				backRemove++;
				didFindBack++;
			}
			j++;
		}
		if (didFindBack == 0)
			break ;
		didFindBack = 0;
		i--;
	}
	//all good so far
	if (frontRemove == ft_strlen(s1))
	{
		return (ft_strdup(""));
	}
	str = ft_calloc(ft_strlen(s1) - frontRemove - backRemove + 1, 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i != (unsigned long) frontRemove)
		i++;
	j = 0;
	while (i < ft_strlen(s1) - backRemove)
	{
		str[j] = s1[i];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
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
