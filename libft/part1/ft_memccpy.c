// #include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void *ft_memccpy(void *pdest, const void *psrc, int c, size_t n)
{
	int i;
	char	*dest;
	char	*src;

	dest = (char *)pdest;
	src = (char *)psrc;
	i = 0;
	while (i != n && src[i] != c)
		i++;
	dest = (char *)malloc(i * sizeof(char));
	i = 0;
	while (n != 0)
	{
		dest[i] = src[i];
		i++;
		if (src[i - 1] == c)
		{
			return ((void *)&dest[i]);
		}
		n--;
	}
	return NULL;
}

// int main(void)
// {
// 	char	src[] = "test truc";
// 	char	*dest;
// 	ft_memccpy (dest, src, 'c', 6);
// 	write(1, dest, 4);
// 	printf("%s", dest);
// 	free(dest);
// }
