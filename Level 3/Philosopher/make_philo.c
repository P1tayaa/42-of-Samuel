/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:28:41 by sboulain          #+#    #+#             */
/*   Updated: 2023/06/13 15:05:12 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

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
	
	i = num_of_phil - 1;
	while (i > 0)
	{
		pthread_join(all_philo[i + 1], all_philo[i]);
		i++;
	}
	
	while (i < num_of_phil)
	{
		pthread_mutex_destroy(&all_philo[i]->left_fork);
		i++;
	}
		free(all_philo);
}



