/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   libft.h											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sboulain <sboulain@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/08/11 19:47:21 by sboulain		  #+#	#+#			 */
/*   Updated: 2022/10/10 21:11:15 by sboulain		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
#include <stddef.h>

size_t	ft_strlen(const char *s);

int		ft_isdigit(int c);

int		ft_isupper(int c);

int		ft_islower(int c);

int		ft_isalpha(int c);

int		ft_isalnum(int c);

int		ft_isascii(int c);

int		ft_isprint(int c);

char	*ft_itoa(int n);

void	*ft_memset(void *s, int c, size_t n);

void	ft_bzero(void *s, size_t n);

char	*ft_strcat(char *dest, const char *src);

char	*ft_strcpy(char *dest, const char *src);

char	*ft_strdup(const char *s);

void	ft_putchar(char c);

void	ft_putstr(char const *s);

void	ft_putnbr(int n);

void	ft_putendl(char const *s);

char	*ft_strnew(size_t size);

char ** ft_split(char const *s, char c);

void	*ft_memccpy(void *pdest, const void *psrc, int c, size_t n);

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);

int		ft_atoi(const char *str);

int		ft_tolower(int c);

int		ft_toupper(int c);

void	*ft_calloc(size_t count, size_t size);

void	*ft_memmove(void *dst, const void *src, size_t len);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcat(char *restrict dst,
			const char *restrict src, size_t dstsize);

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

void	*ft_memchr(const void *s, int c, size_t n);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strtrim(char const *s1, char const *set);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len);

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

#endif