/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:27:20 by sboulain          #+#    #+#             */
/*   Updated: 2023/07/20 13:16:18 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

// void    print_message(char *str, t_philo *all_philo, int id)
// {
//     int    time;

//     pthread_mutex_lock(all_philo->printf);
//     // time = get_current_time() - all_philo->start_time;
//     if (!dead(all_philo))
//         printf("[%d] all_philo[%d] %s\n", time, id, str);
//     pthread_mutex_unlock(all_philo[0]->write_lock);
// }

void	phillo_terminator(t_philo **all_philo, int num_of_phil);

void	make_time_since_last_meal(uint64_t *time_since, uint64_t *last_time_eat)
{
	(*time_since) = (*last_time_eat);
}

void	try_and_eat(t_args_info_plus_philo **arguments, uint64_t *last_time_eat)
{
	int	error;

	pthread_mutex_lock((*(*arguments)->philo)->left_fork);
	pthread_mutex_lock((*(*arguments)->philo)->printf);
	printf("%lu: %d has taken a fork\n", get_time() - (*arguments)->start_time, (*(*arguments)->philo)->num_of_phil);
	pthread_mutex_unlock((*(*arguments)->philo)->printf);

	pthread_mutex_lock((*(*arguments)->philo)->right_fork);

	// if ((*(*arguments)->philo)->num_of_phil % 2 == 1)
	// {
		
	// 	pthread_mutex_lock((*(*arguments)->philo)->left_fork);
	// 	pthread_mutex_lock((*(*arguments)->philo)->printf);
	// 	printf("%lu: %d has taken a fork\n", get_time() - (*arguments)->start_time, (*(*arguments)->philo)->num_of_phil);
	// 	pthread_mutex_unlock((*(*arguments)->philo)->printf);

	// 	pthread_mutex_lock((*(*arguments)->philo)->right_fork);
	// }
	// else
	// {
	// 	pthread_mutex_lock((*(*arguments)->philo)->right_fork);

	// 	pthread_mutex_lock((*(*arguments)->philo)->printf);
	// 	printf("%lu: %d has taken a fork\n", get_time() - (*arguments)->start_time, (*(*arguments)->philo)->num_of_phil);
	// 	pthread_mutex_unlock((*(*arguments)->philo)->printf);

	// 	pthread_mutex_lock((*(*arguments)->philo)->left_fork);
	// }
	

	pthread_mutex_lock((*(*arguments)->philo)->mutex_time_sinse_last_meal);
	pthread_mutex_lock((*(*arguments)->philo)->mutex_num_time_eat);
	*last_time_eat = get_time() - (*arguments)->start_time;
	make_time_since_last_meal((*(*arguments)->philo)->time_sinse_last_meal, last_time_eat);
	(*(*arguments)->philo)->num_time_eat++;
	printf("%lu: %d has taken a fork\n%lu: %d is eating\n", (*(*(*arguments)->philo)->time_sinse_last_meal), (*(*arguments)->philo)->num_of_phil, *last_time_eat, (*(*arguments)->philo)->num_of_phil);
	pthread_mutex_unlock((*(*arguments)->philo)->mutex_num_time_eat);
	pthread_mutex_unlock((*(*arguments)->philo)->mutex_time_sinse_last_meal);
	// error = pthread_mutex_unlock(arguments->philo->printf);
	usleep((*arguments)->arg_info.time_to_eat * 1000);
	error = pthread_mutex_unlock((*(*arguments)->philo)->left_fork);
	error = pthread_mutex_unlock((*(*arguments)->philo)->right_fork);
	// pthread_mutex_lock(arguments->philo->printf);
	pthread_mutex_lock((*(*arguments)->philo)->mutex_time_sinse_last_meal);
	pthread_mutex_lock((*(*arguments)->philo)->mutex_num_time_eat);
	printf("%lu: %d is sleeping\n", get_time() - (*arguments)->start_time, (*(*arguments)->philo)->num_of_phil);
	pthread_mutex_unlock((*(*arguments)->philo)->mutex_num_time_eat);
	pthread_mutex_unlock((*(*arguments)->philo)->mutex_time_sinse_last_meal);
	// error = pthread_mutex_unlock(arguments->philo->printf);
	usleep((*arguments)->arg_info.time_to_sleep * 1000);
}

void think(t_args_info_plus_philo *arguments)
{
	char *print;

	// pthread_mutex_lock(arguments->philo->printf);
	pthread_mutex_lock((*arguments->philo)->mutex_time_sinse_last_meal);
	pthread_mutex_lock((*arguments->philo)->mutex_num_time_eat);
	printf("%lu: %d is thinking\n", get_time() - arguments->start_time, (*arguments->philo)->num_of_phil);
	pthread_mutex_unlock((*arguments->philo)->mutex_num_time_eat);
	pthread_mutex_unlock((*arguments->philo)->mutex_time_sinse_last_meal);
	// pthread_mutex_unlock(arguments->philo->printf);

	// usleep((arguments->arg_info.time_to_eat) / 2 * 1000);
}
void	*thread_phil(void *arg)
{
	t_args_info_plus_philo	*arguments;
	uint64_t	time_start;
	uint64_t	last_time_eat;

	arguments = (t_args_info_plus_philo *)arg;
	pthread_mutex_lock((*arguments->philo)->printf);
	// printf("philo number %d is alive\n", (*arguments->philo) -> num_of_phil);
	pthread_mutex_unlock((*arguments->philo)->printf);
	// pause();
	pthread_mutex_lock((*arguments->philo)->mutex_time_sinse_last_meal);
	pthread_mutex_lock((*arguments->philo)->mutex_num_time_eat);
	(*arguments->philo)->num_time_eat = 0;
	time_start = get_time();
	last_time_eat = time_start;
	arguments->start_time = time_start;
	(*(*arguments->philo)->time_sinse_last_meal) = 0;
	(*arguments->philo)->start_time = time_start;
	pthread_mutex_unlock((*arguments->philo)->mutex_num_time_eat);
	pthread_mutex_unlock((*arguments->philo)->mutex_time_sinse_last_meal);

	if ((*arguments->philo)->num_of_phil % 2 == 1)
		think(arguments);
	while ((*arguments->philo))
	{
		try_and_eat(&arguments, &last_time_eat);
		think(arguments);
	}
	return (NULL);
}
