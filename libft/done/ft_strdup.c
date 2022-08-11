/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:35:35 by sboulain          #+#    #+#             */
/*   Updated: 2022/08/11 21:35:35 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char *ft_strdup(const char *s)
{
    char *dupstr;
    int i;

    dupstr = (char *)malloc(ft_strlen(s) * sizeof(char));
    i = 0;
    while(s[i] != '\0')
    {
        dupstr[i] = s[i];
        i++;
    }
    dupstr[i] = '\0';
    return (dupstr);
}
