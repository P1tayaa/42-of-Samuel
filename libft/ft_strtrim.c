/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:30:56 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/10 21:13:28 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
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
	if (s1[0] == '\0' && set[0] == '\0')
	{
		str = ft_strnew(1);
		if (!str)
			return (NULL);
		// str[0] = '\0';
		return (str);
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
		while(j < ft_strlen(set))
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
		str = ft_strnew(1);
		if (!str)
			return (NULL);
		// str[0] = '\0';
		return (str);
	}
	str = ft_strnew(ft_strlen(s1) - frontRemove - backRemove + 1);
	if (!str)
		return (NULL);
	if (frontRemove + backRemove == ft_strlen(s1))
	{
		str[0] = '\0';
		return (str);
	}
	i = 0;
	while(i != (unsigned long) frontRemove)
		i++;
	j = 0;
	while(i < ft_strlen(s1) - backRemove)
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

// 	str2 = ft_strtrim(str1, set);
// 	printf("%s\n", str2);
// 	free (str2);
// }