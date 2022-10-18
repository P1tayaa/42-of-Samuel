/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:19:44 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/18 23:37:47 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>



char	*get_next_line(int fd)
{
	char			*char_read;
	unsigned long	i;
	
	char_read = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	i = 1;
	printf("%d", fd);

	if(read(fd, char_read, BUFFER_SIZE) == -1)
	{
		printf("%s", char_read);
		i++;
	}
	printf("%d", fd);
	while(i)
	{
		read(fd, char_read, 1);
		printf("%s", char_read);
		i--;
	}
	// write(1, char_read, 10);
	free(char_read);
	return (NULL);
}

#include <fcntl.h>

int main()
{
	int fd;
	fd = open("./file.text" , O_RDONLY);
	get_next_line(fd);
	close(fd);
	printf("");
	return (0);

}