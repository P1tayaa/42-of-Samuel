/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:05:25 by sboulain          #+#    #+#             */
/*   Updated: 2023/06/01 19:04:15 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks_chec(void)
{
	system("leaks -q so_long");
}

char				*get_all_lines(int fd);
char				*open_map(char *map_name);
bool				is_only_1_player(t_map *map);
bool				is_only_1_exit(t_map *map);
bool				is_all_bordes_wall(t_map *map);

int	check(int argc, char **argv, t_map **map)
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

void				error_free_texture(t_texture_images *textures_pointers,
			mlx_t *mlx);
void				player_moves(int x, int y, t_param_for_hook *param_hooks);

void	ft_hook(void *param)
{
	t_param_for_hook	*param_hook;

	param_hook = param;
	if (mlx_is_key_down(param_hook->mlx, MLX_KEY_ESCAPE))
	{
		error_free_texture(param_hook->textures_pointers, param_hook->mlx);
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

t_param_for_hook	*parram_hook_start( t_map *map, mlx_t *mlx)
{
	t_param_for_hook	*param_hook;

	param_hook = malloc(sizeof(t_param_for_hook));
	if (!param_hook)
		exit(1);
	param_hook->textures_pointers = load_map(&mlx, &map);
	param_hook->map = map;
	param_hook->mlx = mlx;
	param_hook->step_done = 0;
	return (param_hook);
}

void				terminate_texture(t_texture_images *texture_pouinter);

int	main(int argc, char **argv)
{
	t_map				*map;
	int					is_bad;
	mlx_t				*mlx;
	t_param_for_hook	*param_hook;

	atexit(leaks_chec);
	is_bad = check(argc, argv, &map);
	if (is_bad != -1)
		return (1);
	mlx = mlx_init((map->max_index_x_right + 1) * 16,
			(map->max_index_y_down + 1) * 16, "main_window", false);
	if (!mlx)
		exit(1);
	param_hook = parram_hook_start(map, mlx);
	if (!mlx_loop_hook(mlx, ft_hook, param_hook))
		error_free_texture(param_hook->textures_pointers, param_hook->mlx);
	mlx_loop(mlx);
	terminate_texture(param_hook->textures_pointers);
	free(param_hook);
	free_map_cells(map);
	mlx_terminate(mlx);
	return (0);
}
