/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:28:41 by sboulain          #+#    #+#             */
/*   Updated: 2023/07/20 13:08:37 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

// bool make_mutex(t_philo *philo)
// {
// 	if (pthread_mutex_init(&philo->right_fork, NULL) != 0)
// 		return (false);
// 	return (true);
// }

t_philo **make_phil(int	num_of_phil)
{
	t_philo			**all_philo;
	int				i;
	pthread_mutex_t	*mutex_printf;

	all_philo = malloc(sizeof(t_philo *) * (num_of_phil + 1));
	i = 0;
	while (i < num_of_phil)
	{
		// printf("phil N %d, making\n", i);
		all_philo[i] = malloc(sizeof(t_philo));
		all_philo[i]-> num_time_eat = 0;
		all_philo[i]-> num_of_phil = i + 1;
		if (i == 0)
		{
			all_philo[0]->printf = malloc(sizeof(pthread_mutex_t));
			pthread_mutex_init((all_philo[0]->printf), NULL);
			mutex_printf = (all_philo[0]->printf);
		}
		// puts("made a mutex");
		all_philo[i]->time_sinse_last_meal = malloc(sizeof(uint64_t));
		all_philo[i]->mutex_num_time_eat = malloc(sizeof(pthread_mutex_t));
		all_philo[i]->mutex_time_sinse_last_meal = malloc(sizeof(pthread_mutex_t));
		all_philo[i]->right_fork = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init((all_philo[i]->mutex_num_time_eat), NULL);
		pthread_mutex_init((all_philo[i]->mutex_time_sinse_last_meal), NULL);
		pthread_mutex_init((all_philo[i]->right_fork), NULL);
		if (i != 0)
		{
			// all_philo[i] -> left_fork = malloc(sizeof(pthread_mutex_t));
			all_philo[i] -> left_fork = all_philo[i - 1] -> right_fork;
		}
		if (i != 0)
		{
			// all_philo[i]->printf = malloc(sizeof(pthread_mutex_t));
			all_philo[i]->printf = mutex_printf;
		}
		i++;
	} 
	all_philo[0] -> left_fork = malloc(sizeof(pthread_mutex_t));
	all_philo[0] -> left_fork = all_philo[i - 1] -> right_fork;
	return (all_philo);
}
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
	if (ft_atoi(argv[4], &temp_num) == false)
		return (args_info);
	args_info.time_to_sleep = temp_num;
	if (argc == 6)
	{
		if (ft_atoi(argv[5], &temp_num) == false)
			return (args_info);
		args_info.number_of_times_each_philosopher_must_eat = temp_num;
		printf("%d\n", args_info.number_of_times_each_philosopher_must_eat);
	}
	args_info.all_good = true;
	return (args_info);
}

// ! have to do
void	phillo_terminator(t_philo ***all_philo, int num_of_phil)
{
	int	i;
	
	puts("\n\n\n");
	i = num_of_phil - 1;
	while (i > 0)
	{
		
		pthread_detach(*(*all_philo)[i]->current_thread);
		i--;
	}
	// pthread_mutex_destroy(&all_philo[0]->printf);
	while (i < num_of_phil)
	{
		pthread_mutex_destroy((*all_philo)[i]->left_fork);
		pthread_mutex_destroy((*all_philo)[i]->mutex_num_time_eat);
		pthread_mutex_destroy((*all_philo)[i]->mutex_time_sinse_last_meal);
		i++;
	}
		free((*all_philo));
	// exit(0);
}



