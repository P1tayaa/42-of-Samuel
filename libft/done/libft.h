/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 19:47:21 by sboulain          #+#    #+#             */
/*   Updated: 2022/08/11 19:47:21 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
#include <stddef.h>

size_t  ft_strlen(const char *s);

char	*ft_itoa(int n);

void	*ft_memset(void *s, int c, size_t n);

void	ft_bzero(void *s, size_t n);

char	*ft_strcat(char *dest, const char *src);

char	*ft_strcpy(char *dest, const char *src);

char	*ft_strdup(const char *s);

void ft_putchar(char c);

void ft_putstr(char const *s);

void ft_putnbr(int n);

void ft_putendl(char const *s);

char * ft_strnew(size_t size);

char * ft_strjoin(char const *s1, char const *s2);

char ** ft_strsplit(char const *s, char c);

#endif