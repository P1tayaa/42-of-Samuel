// #include <stdlib.h>
// #include <unistd.h>
#include <libft.h>

void *memccpy(void *dest, const void *src, int c, size_t n)
{
	int i;
	void *pointer;

	pointer = src;
	i = 0;
	while (*pointer != c && i < n)
	{
		i++;
		pointer++;
	}
	if (i == 0)
		return NULL;
	dest = (char*)malloc(i * sizeof(char));
	pointer = src;
	while (*pointer != c && i < n)
	{
		*dest = *src;
		dest++;
		pointer++;
	}
}

// int main(void)
// {
// 	char	src[] = "test truc";
// 	char	*dest;
// 	memccpy (dest, src, 't', 6);
// 	write(1, dest, 4);
// 	free(dest);
// }