/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:20:50 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/27 13:18:34 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

int	ft_atoi_base(int number, int base, int isfirst, char lettle);

int	ft_atoui_base(unsigned int number, unsigned int base,
		int isfirst, char lettle);

int	ft_atoull_base(unsigned long long number, unsigned long long base,
		int isfirst, char lettle);

int	manage_print(char const *input, size_t *i, va_list arg);

int	get_purcentage_signs(char const *input, va_list arg);

int	ft_printf(const char *input, ...);

#endif
