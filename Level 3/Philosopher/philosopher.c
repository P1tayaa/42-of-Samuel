/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:27:20 by sboulain          #+#    #+#             */
/*   Updated: 2023/06/13 14:46:44 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

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
		usleep(1);
	}
	time_start = get_time();
	last_time_eat = time_start;
	arguments->start_time = time_start;
	if (arguments->philo->num_of_phil % 2 == 1)
		think(arguments);
	while (arguments->philo)
	{
		// put_str("test\n");
		try_and_eat(arguments, &last_time_eat);
		think(arguments);
		usleep(1);
	}
	return (NULL);
}