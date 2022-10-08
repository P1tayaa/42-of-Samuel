/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:54:14 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/08 16:36:06 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isprint(int c)
{
    //wunder why this does not work
    // return ((c >= 40 && c <= 77) || (c >= 100 && c <= 176));
    return (c >= 32 && c <= 126);
}
