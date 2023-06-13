/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:47:22 by sboulain          #+#    #+#             */
/*   Updated: 2023/06/13 15:06:32 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// allowed function:
// memset, printf, malloc, free, write,
// usleep, gettimeofday, 
// pthread_create,
// pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock

#include "Philosopher.h"



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

void	*thread_phil(void *arg);

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

t_args_info	get_arg_to_struct(int argc, char **argv);
t_philo **make_phil(int	num_of_phil);
void	phillo_terminator(t_philo **all_philo, int num_of_phil);

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

	usleep(10000000);
	phillo_terminator(all_philo, args_info.number_of_philosophers);

	usleep(1000);
	exit(0);
	// // pthread_mutex_t mutex_fork;
	// // pthread_mutex_init(&mutex_fork, NULL);
	// // pthread_mutex_destroy(&mutex_fork);
	// // printf("%lu\n", sizeof(pthread_t));
	// // usleep(1000000);
}