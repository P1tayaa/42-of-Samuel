/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:05:25 by sboulain          #+#    #+#             */
/*   Updated: 2023/05/29 20:21:41 by sboulain         ###   ########.fr       */
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
	if (map_location == NULL)
		exit(1);
	if (ft_memcmp(&map_name[ft_strlen(map_name) - 4], ber, 4) != 0)
		return (free(map_location), NULL);
	file_discriptor = open(map_location, O_RDONLY);
	if (file_discriptor == -1)
		return (free(map_location), NULL);
	all_file_string = get_all_lines(file_discriptor);
	free(map_location);
	close(file_discriptor);
	return (all_file_string);
}

void	leaks_chec(void)
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
	int	i;

	i = 0;
	while (i <= map ->max_index_x_right)
	{
		if (!(map -> cells[0][i].type == '1' && map
			-> cells[map ->max_index_y_down][i].type == '1'))
			return (false);
		i++;
	}
	i = 0;
	while (i <= map ->max_index_y_down)
	{
		if (map -> cells[i][0].type != '1' && map
			-> cells[i][map ->max_index_x_right].type != '1')
			return (false);
		i++;
	}
	return (true);
}

int		check(int argc, char **argv, t_map **map)
{
	char	*map_string;

	if (argc != 2)
		return (ft_printf("agrs wrong"));
	map_string = open_map(argv[1]);
	if (map_string == NULL)
		return (ft_printf("file don't exist or is not .ber"));
	if (is_map_valid_char(map_string) == false)
		return (ft_printf("map incorect"));
	*map = make_map(map_string);
	free(map_string);
	if (is_only_1_player(*map) == false)
		return (free_map_cells(*map), ft_printf("not only 1 player\n"));
	if (is_only_1_exit(*map) == false)
		return (free_map_cells(*map), ft_printf("not only 1 exit\n"));
	if (is_all_bordes_wall(*map) == false)
		return (free_map_cells(*map), ft_printf("not border wall\n"));
	if (check_flud_fill_main(map) == false)
		return (free_map_cells(*map), ft_printf("game not doable\n"));
	return (-1);
}

void	error_free_texture(t_texture_images *textures_pointers);
void	player_moves(int x, int y, t_param_for_hook *param_hooks);

void	ft_hook(void *param)
{
	t_param_for_hook	*param_hook;

	param_hook = param;
	if (mlx_is_key_down(param_hook->mlx, MLX_KEY_ESCAPE))
	{
		error_free_texture(param_hook->textures_pointers);
		mlx_close_window(param_hook->mlx);
	}
	else if (mlx_is_key_down(param_hook->mlx, MLX_KEY_W))
		player_moves(0, 1, param);
	else if (mlx_is_key_down(param_hook->mlx, MLX_KEY_S))
		player_moves(0, -1, param);
	else if (mlx_is_key_down(param_hook->mlx, MLX_KEY_A))
		player_moves(-1, 0, param);
	else if (mlx_is_key_down(param_hook->mlx, MLX_KEY_D))
		player_moves(1, 0, param);
}

t_texture_images	*load_map(mlx_t **mlx, t_map **map);

int	main(int argc, char **argv)
{
	t_map				*map;
	int 				is_bad;
	mlx_t				*mlx;
	t_param_for_hook	*param_hook;

	atexit(leaks_chec);
	is_bad = check(argc, argv, &map);
	if (is_bad != -1)
		return(1);
	mlx = mlx_init((map->max_index_x_right + 1) * 16, (map->index_of_player_y + 3) * 16, "main_window", false);
	if (!mlx)
		exit(1);
	param_hook = malloc(sizeof(param_hook));
	if (!param_hook)
		exit(1);
	param_hook->textures_pointers = load_map(&mlx, &map);	
	param_hook->map = map;
	param_hook->mlx = mlx;
	param_hook->step_done = 0;
	mlx_loop_hook(mlx, ft_hook, param_hook);
	mlx_loop(mlx);
	error_free_texture(param_hook->textures_pointers);
	mlx_terminate(mlx);
	ft_printf("%d, %d\n", map->index_of_player_x, map->index_of_player_y);
	free(param_hook);
	free_map_cells(map);
	usleep(30000);
	return (0);
}
