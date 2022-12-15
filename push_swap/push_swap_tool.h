/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:20:50 by sboulain          #+#    #+#             */
/*   Updated: 2022/11/22 14:23:51 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>

int	ft_isdigit(int c);

int ft_itoa(char *input);

int	is_all_digit(char **input, int num_arg);

typedef struct s_vector_int_with_index
{
	int	    		*number;
    unsigned int    *index;
	int             lenght;
}					s_vector_int_with_index;


#endif
