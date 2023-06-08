/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:47:22 by sboulain          #+#    #+#             */
/*   Updated: 2023/06/08 19:54:01 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// allowed function:
// memset, printf, malloc, free, write,
// usleep, gettimeofday, 
// pthread_create,
// pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock


// pthread_create create a thread and start it
// pthread_detach kill the thread if it still alive
//pthread_join
#include "Philosopher.h"
uint64_t	get_time()
{
	struct timeval	time;
	
	gettimeofday(&time, NULL);
	return ((time.tv_sec * (uint64_t)1000) + (time.tv_usec / (uint64_t)1000));
}

void	try_and_eat(t_args_info_plus_philo *arguments, uint64_t *last_time_eat)
{
	int	error;
	
	pthread_mutex_lock(&arguments->philo->left_fork);
	printf("%llu: %d has taken a fork\n", get_time() - arguments->start_time, arguments->philo->num_of_phil);
	pthread_mutex_lock(&arguments->philo->right_fork);
	*last_time_eat = get_time() - arguments->start_time;
		printf("%llu: %d has taken a fork\n%llu: %d is eating\n", *last_time_eat, arguments->philo->num_of_phil, *last_time_eat, arguments->philo->num_of_phil);
	usleep(arguments->arg_info.time_to_eat * 1000);
	error = pthread_mutex_unlock(&arguments->philo->left_fork);
	error = pthread_mutex_unlock(&arguments->philo->right_fork);
	printf("%llu: %d is sleeping\n", get_time() - arguments->start_time, arguments->philo->num_of_phil);
	usleep(arguments->arg_info.time_to_sleep * 1000);
}

void think(t_args_info_plus_philo *arguments)
{
	char *print;

		printf("%llu: %d is thinking\n", get_time() - arguments->start_time, arguments->philo->num_of_phil);
	// printf("%d\n\n", arguments->arg_info.time_to_sleep);
	usleep(arguments->arg_info.time_to_sleep * 1000);
}
void	*thread_phil(void *arg)
{
	t_args_info_plus_philo	*arguments;
	uint64_t	time_start;
	uint64_t	last_time_eat;

	arguments = (t_args_info_plus_philo *)arg;
	printf("philo number %d is alive\n", arguments -> philo -> num_of_phil);
	while (*(arguments -> philo-> start) == false)
	{
		// put_num(arguments->philo->num_of_phil);
		usleep(1);
	}
	time_start = get_time();
	last_time_eat = time_start;
	arguments->start_time = time_start;
	// write(1, "OK\n", 3);
	// put_num_64(time_start);
	// write(1, "\n", 1);
	// try and eat
	if (arguments->philo->num_of_phil % 2 == 1)
		think(arguments);
	while (arguments->philo)
	{
		// put_str("test\n");
		try_and_eat(arguments, &last_time_eat);
		think(arguments);
		usleep(1);
	}
	
	// if time of dead then die
	// try and eat
		// when done sleep
	// try and think
	// while (1 == 1)
	// {
	// 	put_num((int)time.tv_usec);
	// 	write(1, "\n", 1);
	// 	usleep(100000);
	// }
	return (NULL);
}

bool make_mutex(t_philo *philo)
{
	if (pthread_mutex_init(&philo->right_fork, NULL) != 0)
		return (false);
	return (true);
}

t_philo **make_phil(int	num_of_phil)
{
	t_philo **all_philo;
	int		i;
	bool	*start;
	pthread_mutex_t *mutex_old_fork;

	all_philo = malloc(sizeof(t_philo *) * (num_of_phil + 1));
	i = 0;
	*start = false;
	while (i < num_of_phil)
	{
		all_philo[i] = malloc(sizeof(t_philo));
		all_philo[i]-> num_time_eat = 0;
		all_philo[i]-> num_of_phil = i + 1;
		all_philo[i]-> start = start;
		pthread_mutex_init(&(all_philo[i]->right_fork), NULL);
		if (i != 0)
			all_philo[i] -> left_fork = *mutex_old_fork;
		mutex_old_fork = &all_philo[i] -> right_fork;
		i++;
	} 
	all_philo[0] -> left_fork = all_philo[i - 1] -> right_fork;
	return (all_philo);
}

// void	print_phil_content(t_philo **phillos, int	num_of_phil)
// {
// 	int	i;

// 	i = 0;
// 	while (i < num_of_phil)
// 	{
// 		printf("the philo %d, has address %p, left fork: %d right fork: %d\n", phillos[i]->num_of_phil, phillos[i], phillos[i]->left_fork, phillos[i]->right_fork);
// 		i++;
// 	} 
// }


//args:
// number_of_philosophers time_to_die time_to_eat
// time_to_sleep
// [number_of_times_each_philosopher_must_eat]

t_args_info	get_arg_to_struct(int argc, char **argv)
{
	t_args_info args_info;
	int			temp_num;

	args_info.all_good = false;
	if (ft_atoi(argv[1], &temp_num) == false)
		return (args_info);
	args_info.number_of_philosophers = temp_num;
	if (ft_atoi(argv[2], &temp_num) == false)
		return (args_info);
	args_info.time_to_die = temp_num;
	if (ft_atoi(argv[3], &temp_num) == false)
		return (args_info);
	args_info.time_to_eat = temp_num;
	if (ft_atoi(argv[3], &temp_num) == false)
		return (args_info);
	args_info.time_to_sleep = temp_num;
	if (argc == 5)
	{
		if (ft_atoi(argv[3], &temp_num) == false)
			return (args_info);
		args_info.time_to_sleep = temp_num;
	}
	args_info.all_good = true;
	return (args_info);
}

// ! have to do
void	phillo_terminator(t_philo **all_philo, int num_of_phil)
{
	int	i;
	
	i = 0;
	while (i < num_of_phil)
	{
		pthread_mutex_destroy(&all_philo[i]->left_fork);
		i++;
	}
		free(all_philo);
}

void	start_threads(t_philo *philo, t_args_info	args_info)
{
	t_args_info_plus_philo	*arg_temp;
	pthread_t				my_thread;
	t_args_info				args_info_for_philo;
	
	arg_temp = malloc(sizeof(t_args_info_plus_philo));
	if (!arg_temp)
		exit(1);
	args_info_for_philo.all_good = args_info.all_good;
	args_info_for_philo.number_of_philosophers = args_info.number_of_philosophers;
	args_info_for_philo.number_of_times_each_philosopher_must_eat = args_info.number_of_times_each_philosopher_must_eat;
	args_info_for_philo.time_to_die = args_info.time_to_die;
	args_info_for_philo.time_to_eat = args_info.time_to_eat;
	args_info_for_philo.time_to_sleep = args_info.time_to_sleep;
	arg_temp -> arg_info = args_info_for_philo;
	arg_temp -> philo = philo;
	philo -> current_thread = &my_thread;
	pthread_create(&my_thread, NULL, &thread_phil, arg_temp);
}

void	start_threads_of_philo(t_philo **all_philo, t_args_info	args_info)
{
	int	i;

	i = 0;
	while (i < args_info.number_of_philosophers)
	{
		start_threads(all_philo[i], args_info);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	t_philo **all_philo;
	t_args_info	args_info;

	if (argc < 5 || argc > 6)
		return (printf("arg wrongs\n"));
	args_info = get_arg_to_struct(argc, argv);
	if (args_info.all_good == false)
		return (printf("arg wrongs 2\n"));
	i = 0;
	all_philo = make_phil(args_info.number_of_philosophers);
	
	// pthread_t thread;
	// print_phil_content(all_philo, args_info.number_of_philosophers);
	start_threads_of_philo(all_philo, args_info);
	// * how to start a thead
	// // pthread_create(&thread, NULL, &thread_phil, NULL);
	usleep(1000000);
	*(all_philo[0]->start) = true;
	// // pthread_create(&thread, NULL, &thread_phil, NULL);
	// // usleep(1000000);

	while (1)
		usleep(1);
	// // pthread_mutex_t mutex_fork;
	// // pthread_mutex_init(&mutex_fork, NULL);
	// // pthread_mutex_destroy(&mutex_fork);
	// // printf("%lu\n", sizeof(pthread_t));
	// // usleep(1000000);
}