/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:05:25 by sboulain          #+#    #+#             */
/*   Updated: 2023/02/08 20:48:48 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_all_lines(int fd)
{
	char	*all_file_string;
	char	*temp_all_file;
	char	*new_line;

	all_file_string = NULL;
	new_line = get_next_line(fd);
	while (new_line != NULL)
	{
		if (all_file_string == NULL)
			temp_all_file = ft_strdup(new_line);
		else
		{
			temp_all_file = ft_strjoin(all_file_string, new_line);
			free(all_file_string);
		}
		all_file_string = temp_all_file;
		temp_all_file = NULL;
		free(new_line);
		new_line = get_next_line(fd);
	}
	return (all_file_string);
}

char	*open_map(char *map_name)
{
	char		*map_location;
	int			file_discriptor;
	const char	*ber = ".ber";
	char		*all_file_string;

	map_location = ft_strjoin("./maps/", map_name);
	if (ft_memcmp(&map_name[ft_strlen(map_name) - 4], ber, 4) != 0)
		return(free(map_location), NULL);
	file_discriptor = open(map_location, O_RDONLY);
	if (file_discriptor == -1)
		return(free(map_location), NULL);
	all_file_string = get_all_lines(file_discriptor);
	free(map_location);
	close(file_discriptor);
	return (all_file_string);
}

void leaks_chec(void)
{
	system("leaks -q so_long");
}

bool	is_only_1_player(t_map *map)
{
	int		i;
	int		j;
	bool	is_player;

	i = -1;
	is_player = false;
	while (++i <= map ->max_index_y_down)
	{
		j = 0;
		while (j <= map ->max_index_x_right)
		{
			if (map->cells[i][j].has_player == 1 && is_player == false)
			{
				is_player = true;
				map ->index_of_player_x = j;
				map ->index_of_player_y = i;
			}
			else if (map->cells[i][j].has_player == 1 && is_player == true)
				return (false);
			j++;
		}
	}
	if (is_player == false)
		return (false);
	return (true);
}

bool	is_only_1_exit(t_map *map)
{
	int		i;
	int		j;
	bool	is_exit;

	i = -1;
	is_exit = false;
	while (++i <= map ->max_index_y_down)
	{
		j = 0;
		while (j <= map -> max_index_x_right)
		{
			if (map->cells[i][j].type == 'E' && is_exit == false)
			{
				is_exit = true;
			}
			else if (map->cells[i][j].type == 'E' && is_exit == true)
				return (false);
			j++;
		}
	}
	if (is_exit == false)
		return (false);
	return (true);
}

bool	is_all_bordes_wall(t_map *map)
{
	int i;

	i = 0;
	while (i <= map ->max_index_x_right)
	{
		if (!(map -> cells[0][i].type == '1' && map -> cells[map ->max_index_y_down][i].type == '1'))
			return (false);
		i++;
	}
	i = 0;
	while (i <= map ->max_index_y_down)
	{
		if (map -> cells[i][0].type != '1' && map -> cells[i][map ->max_index_x_right].type != '1')
			return (false);
		i++;
	}
	return (true);
}

int		check(int argc, char **argv, t_map **map)
{
	char	*map_string;

	//get content of file
	if (argc != 2)
		return (ft_printf("agrs wrong"));
	map_string = open_map(argv[1]);
	// ft_printf("%s\n",map_string);


	if (map_string == NULL)
		return (ft_printf("file don't exist or is not .ber"));
	//free(map_string);

	//make sure content is corrert char per line and what char inside
	if (is_map_valid_char(map_string) == false)
		return(ft_printf("map incorect"));

	//make map with the correct cells
	*map = make_map(map_string); 
	// make sure 1 and only 1 player
	if (is_only_1_player(*map)== false)
		return (free_map_cells(*map), ft_printf("not only 1 player"));
	// make sure 1 and only 1 exit
	if (is_only_1_exit(*map)== false)
		return (free_map_cells(*map), ft_printf("not only 1 exit"));
	//make all border are 1/wall
	if (is_all_bordes_wall(*map) == false)
		return(free_map_cells(*map), ft_printf("not border wall"));

	return (-1);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	int is_bad;
	
	atexit(leaks_chec);
	is_bad = check(argc, argv, &map);

	if (is_bad != -1)
		return(1);
	// print_map(map);

	// free cells in map
	//so it fees in time


	// ! mlx stuff
	void	*mlx;
	void	*mlx_window_my_game;
	int		x_res;
	int		y_res;

	x_res = 300;
	y_res = 300;
	mlx = mlx_init();
	mlx_window_my_game = mlx_new_window(mlx, x_res, y_res, "Hellow world");
	//mlx_new_image(mlx, 1920, 1080);
	mlx_loop(mlx);

	// ft_printf("%d, %d\n", map->index_of_player_x, map->index_of_player_y);

	// print_map(map);

	check_flud_fill_main(&map);

	free_map_cells(map);
	usleep(30000);
	return (0);
}
