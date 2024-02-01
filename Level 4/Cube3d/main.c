#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include "MLX42.h"

// #define M_PI 3.14159265358979323846264338327950288


// Structure to represent a point in 2D space
typedef struct s_coord
{
	double x;
	double y;
} t_coord;

t_coord mk_coord(double x, double y)
{
	t_coord new_coord;

	new_coord.x = x;
	new_coord.y = y;
	return (new_coord);
}

typedef struct s_vector
{
	// t_coord direction;
	double  angle;
	// it could also be just add angle
	// is the hypotheus, if the direction is the end point
	double  magnitude;
} t_vector;


int exemple() {

	double angle = 60.0; // Angle in degrees

	double radians = angle * (M_PI / 180.0); // Convert to radians

	double cosineResult = cos(radians);

	printf("Cosine: cos(%.2lf degrees) = %.2lf\n", angle, cosineResult);

	return 0;
}

t_coord get_destitaion_vector(t_vector vector)
{
	double  x;
	double  y;
	double  absolute_positive_angle;

	absolute_positive_angle = vector.angle;
	while (absolute_positive_angle > 90)
	{
		absolute_positive_angle = absolute_positive_angle - 90;
	}
	x = cos(absolute_positive_angle * (M_PI / 180));
	y = sin(absolute_positive_angle * (M_PI / 180));
	if (vector.angle <= 90)
		return (mk_coord(x, y));
	if (vector.angle <= 180)
		return (mk_coord(x, -y));
	if (vector.angle <= 270)
		return (mk_coord(-x, -y));
	// if (vector.angle <= 360)
	return (mk_coord(-x, y));
}

t_coord get_intersection_at_x_of_vector(t_vector vector, int x)
{
	double  local_x;
	double  y;
	double  absolute_positive_angle;

	absolute_positive_angle = vector.angle;
	if (x < 0)
		local_x = -(double)x;
	else
		local_x = (double)x;
	while (absolute_positive_angle > 90)
	{
		// printf("absolute_positive_angle is %f\n", absolute_positive_angle);
		absolute_positive_angle -= (double)90;
	}
	y = x * tan(absolute_positive_angle * (M_PI / 180));
	if (vector.angle <= 90)
		return (mk_coord(local_x, y));
	if (vector.angle <= 180)
		return (mk_coord(local_x, -y));
	if (vector.angle <= 270)
		return (mk_coord(-local_x, -y));
	// if (vector.angle <= 360)
	return (mk_coord(-local_x, y));
}

t_coord get_intersection_at_y_of_vector(t_vector vector, int y)
{
	double  x;
	double  local_y;
	double  absolute_positive_angle;

	absolute_positive_angle = vector.angle;
	if (y < 0)
		local_y = -(double)y;
	else
		local_y = (double)y;
	while (absolute_positive_angle > 90)
	{
		absolute_positive_angle = absolute_positive_angle - 90;
	}
	x = (double)y * tan(absolute_positive_angle * (M_PI / 180));
	if (vector.angle <= 90)
		return (mk_coord(x, local_y));
	if (vector.angle <= 180)
		return (mk_coord(x, -local_y));
	if (vector.angle <= 270)
		return (mk_coord(-x, -local_y));
	// if (vector.angle <= 360)
	return (mk_coord(-x, local_y));
}

t_coord *ray_casting_to_find_wall(int map[10][10], t_coord player_position, double angle)
{
	int lenght_check = 15;
	int i = 0;
	int j = 0;
	double  randiant_angle_looking = (angle) * (M_PI / 180);
	// printf("current angle is %f, radian it %f\n", angle, randiant_angle_looking);

	// t_coord fardest_point = mk_coord(lenght_check * cos(randiant_angle_looking), lenght_check * sin(randiant_angle_looking));
	t_vector    direction_ray;
	direction_ray.magnitude = lenght_check;
	direction_ray.angle = angle;
	t_coord fardest_point = get_destitaion_vector(direction_ray);
	puts("test");
	
	// printf("fardestpoint is (%f, %f)\n", fardest_point.x, fardest_point.y);
	double current_x = 0;
	double current_y = 0;
	t_coord cur_coord;
	cur_coord = mk_coord(0, 0);
	printf("current angle %f\n", angle);
	while (fardest_point.x != floor(cur_coord.x))
	{
		current_x = floor(cur_coord.x);
		if (fardest_point.x >= 0)
			current_x++;
		else
			current_x--;
		cur_coord = mk_coord(current_x, current_x / tan((direction_ray.angle) * (M_PI / 180)));
		// printf("curentposition looking is (%f, %f)\n", cur_coord.x, cur_coord.y)
		// need to replace with map bound check
		printf("curentposition looking is (%f, %f)\n", cur_coord.x + player_position.x, -cur_coord.y + player_position.y);
		if ((int)round(-cur_coord.y + player_position.y) < 0 || (int)round(cur_coord.x + player_position.x) < 0)
		{
			printf("curentposition looking is (%f, %f)\n", cur_coord.x, cur_coord.y);
			puts("found wall at neg values");
			// return (NULL);
			break ;
		}
		if ((int)round(-cur_coord.y + player_position.y) > 9 || (int)round(cur_coord.x + player_position.x) > 9)
		{
			printf("curentposition looking is (%f, %f)\n", cur_coord.x, cur_coord.y);
			puts("looking beyound map");
			// return (NULL);
			break ;
		}
		if (map[(int)round(-cur_coord.y + player_position.y)][(int)round(cur_coord.x + player_position.x)] == 1)
		{
			puts("wall!");
			t_coord *good_coord = malloc(sizeof(t_coord));
			*good_coord = mk_coord((int)round(cur_coord.x + player_position.x), (int)round(-cur_coord.y + player_position.y)); 
			printf("final pos looking is (%f, %f)\n", (*good_coord).x, (*good_coord).y);
			return (good_coord);
		}
	}
	current_x = 0;
	current_y = 0;
	cur_coord = mk_coord(0, 0);
	while (fardest_point.y != floor(cur_coord.y) + 1)
	{
		current_y = floor(cur_coord.y);
		if (fardest_point.y >= 0)
			current_y++;
		else
			current_y--;
		cur_coord = mk_coord(current_y * tan((direction_ray.angle) * (M_PI / 180)), current_y);
		// cur_coord = mk_coord(current_x, current_x * tan((direction_ray.angle / 360 * 90) * (M_PI / 180)));

		// puts("checks");
		// puts("checks");
		// puts("checks");
		// puts("checks");
		// puts("checks");
		if ((int)round(-cur_coord.y + player_position.y) < 0 || (int)round(cur_coord.x + player_position.x) < 0)
		{
			printf("curentposition looking is (%f, %f)\n", cur_coord.x, cur_coord.y);
			puts("found wall at neg values");
			return (NULL);
		}
		if ((int)round(-cur_coord.y + player_position.y) > 9 || (int)round(cur_coord.x + player_position.x) > 9)
		{
			printf("curentposition looking is (%f, %f)\n", cur_coord.x, cur_coord.y);
			puts("looking beyound map");
			return (NULL);
		}
		if (map[(int)round(-cur_coord.y + player_position.y)][(int)round(cur_coord.x + player_position.x)] == 1)
		{
			t_coord *good_coord = malloc(sizeof(t_coord));
			*good_coord = mk_coord((int)round(cur_coord.x + player_position.x), (int)round(-cur_coord.y + player_position.y)); 
			printf("final pos looking is (%f, %f)\n", (*good_coord).x, (*good_coord).y);
			return (good_coord);
		}
	}
	puts("didn't found wall");
	return (NULL);
}


t_coord **player_action()
{
	int map[10][10] = {
		//   0  1  2  3  4  5  6  7  8  9
	/*0*/   {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	/*1*/   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	/*2*/   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	/*3*/   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	/*4*/   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	/*5*/   {1, 0, 0, 0, 0, 2, 0, 0, 0, 1},
	/*6*/   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	/*7*/   {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
	/*8*/   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	/*9*/   {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};



	t_coord player_position = mk_coord(5, 5);
	double angle_looking = 0;

	double angle_drift = 5;
	double  view_angle = 60;
	t_coord **all_walls;
	int     current_wall_index = 0;
	double  current_angle = angle_looking - (view_angle / 2);
	double  final_angle = angle_looking + (view_angle / 2);
	double  number_of_found_walls = ceil(view_angle / angle_drift);

	all_walls = malloc(sizeof(t_coord *) * (number_of_found_walls + 1));
	while (final_angle > current_angle)
	{
		printf("current angle is %f'\n", current_angle);
		t_coord *current_wall;
		if (current_angle < 0)
			current_wall =  ray_casting_to_find_wall(map, player_position, current_angle + 360);
		else if (current_angle > 360)
			current_wall =  ray_casting_to_find_wall(map, player_position, current_angle - 360);
		else
			current_wall =  ray_casting_to_find_wall(map, player_position, current_angle);
		printf("address of currentwall %p\n", current_wall);
		if (current_wall != NULL)
		{
			if (current_wall_index == 0)
			{
				all_walls[current_wall_index] = current_wall;
				printf("wall found at (%f, %f)\n", (*all_walls[current_wall_index]).x, (*all_walls[current_wall_index]).y);
				current_wall_index++;
			}
			else if ((*current_wall).x == (*all_walls[current_wall_index - 1]).x && (*current_wall).y == (*all_walls[current_wall_index - 1]).y)
			{
				printf("curent (%f, %f), last was (%f, %f)\n", (*current_wall).x ,(*current_wall).y, (*all_walls[current_wall_index - 1]).x, (*all_walls[current_wall_index - 1]).y);
				puts("dup wall");
			}
			else
			{
				all_walls[current_wall_index] = current_wall;
				printf("wall found at (%f, %f)\n", (*all_walls[current_wall_index]).x, (*all_walls[current_wall_index]).y);
				current_wall_index++;
			}
			puts("");
		}
		current_angle = current_angle + angle_drift;
	}
	all_walls[current_wall_index] = NULL;
	// int map_emty[10][10] = {
	//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	// };
	// map_emty[(int)player_position.y][(int)player_position.x] = 3;
	// current_wall_index = 0;;
	// while (all_walls[current_wall_index] != NULL)
	// {
	//     map_emty[(int)(*all_walls[current_wall_index]).y][(int)(*all_walls[current_wall_index]).x] = 1;
	//     current_wall_index++;
	// }

	// int i = 0;
	// int j;
	// while (i < 10)
	// {
	//     j = 0;
	//     while (j < 10)
	//     {
	//         printf("[%d]", map_emty[i][j]);
	//         j++;
	//     }
	//     printf("\n");
	//     i++;
	// }
}
typedef struct s_param_mlx
{
	mlx_t *mlx;
	mlx_image_t* image_to_draw_pixel;
} t_param_mlx;

typedef	struct s_stack
{
	t_coord stack[1000];
	int top;
}	t_stack;

t_stack *init_stack()
{
	t_stack * stack = malloc(sizeof(t_stack));
	stack->top = -1;
	return(stack);
}

bool	stack_full(t_stack *stack)
{
	return (stack->top == 999);
}

bool	stack_empty(t_stack *stack)
{
	return(stack->top == -1);
}
t_coord	stack_pop(t_stack *stack)
{
	if (stack_empty(stack))
	{
		printf("empty stack pop");
	}
	return (stack->stack[stack->top--]);
}


void	stack_add(t_stack *stack, t_coord cord)
{
	if (stack_full)
		printf("added to full stack");
	stack->stack[stack->top++] = cord;
}

// needs to be more obimised for later
bool	is_in_stack(t_stack *stack,t_coord	cord)
{
	int i;
	while (i < stack->top)
	{
		if (stack->stack[i].x == cord.x && stack->stack[i].y == cord.y)
			return (true);
		i++;
	}
	return (false);
}



void	draw_line(t_coord	a,	t_coord	b, t_param_mlx *param_real, uint32_t	collor)
{
	t_vector	vector;
	vector.magnitude = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
	vector.angle = atan2(a.y - b.y, a.x - b.x );
	t_coord	temp;
	if (a.x > b.x || a.y > b.y)
	temp = a;
	else
		temp = b;
	double	i = 0;
	t_stack	*cords;
	cords = init_stack();
	while (i < vector.magnitude)
	{
		if (!is_in_stack(cords, mk_coord(temp.x + i * cos(vector.angle), temp.y +  i * sin(vector.angle))))
			stack_add(cords, mk_coord(temp.x + i * cos(vector.angle), temp.y + i * sin(vector.angle)));
		i++;
	}
	int j = 0;
	while (j < cords->top)
	{
		printf("x = %f, y = %f\n", cords->stack[j].x, cords->stack[j].y);
		mlx_put_pixel(param_real->image_to_draw_pixel, cords->stack[j].x, cords->stack[j].y, collor);
		j++;
	}
	mlx_image_to_window(param_real->mlx, param_real->image_to_draw_pixel, 0, 0);
}

void    ft_hook(void    *param)
{
	t_param_mlx *param_real;

	param_real = (t_param_mlx *)param;
	if (mlx_is_key_down(param_real->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(param_real->mlx);
	}
	if (mlx_is_key_down(param_real->mlx, MLX_KEY_W))
		draw_line(mk_coord(0, 0), mk_coord(500, 500), param_real, 255 * 256 * 256 + 255 * 256 + 255);
}


int main()
{
	t_coord A;
	t_coord B;
	t_param_mlx *param_mlx;

	double  angle;
	player_action();
	param_mlx = malloc(sizeof(t_param_mlx));
	// pause();
	mlx_t   *mlx;
	mlx = mlx_init(1080,720, "main_window", false);
	param_mlx->image_to_draw_pixel = mlx_new_image(mlx, 1080,720);
	if (!mlx)
		exit(1);
	param_mlx->mlx = mlx;
	mlx_loop_hook(mlx, ft_hook, param_mlx);
	mlx_loop(mlx);
	// pause();
	return (0);
}
