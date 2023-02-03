/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:05:25 by sboulain          #+#    #+#             */
/*   Updated: 2023/02/03 21:30:17 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*open_map(char *map_name)
{
	char		*map_location;
	int			file_discriptor;
	const char	*ber = ".ber";

	map_location = ft_strjoin("./maps/", map_name);
	if (ft_memcmp(&map_name[ft_strlen(map_name) - 4], ber, 4) != 0)
		return(free(map_location), NULL);
	file_discriptor = open(map_location, O_RDONLY);
		if (file_discriptor == -1)
			return(free(map_location), NULL);
		//need to get stuff
	close(file_discriptor);
	return (NULL);
}

int	main(int argc, char **argv)
{
	char	*map_string;

	if (argc != 2)
		return (ft_printf("agrs wrong"));
	map_string = open_map(argv[1]);
}
