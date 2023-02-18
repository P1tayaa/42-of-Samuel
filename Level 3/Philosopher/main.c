/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:47:22 by sboulain          #+#    #+#             */
/*   Updated: 2023/02/18 19:52:56 by sboulain         ###   ########.fr       */
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

void	*thread_phil(void *arg)
{
	t_philo	*me;
	struct timeval	time;

	me = (t_philo *)arg;
	gettimeofday(&time, NULL);
	while (1 == 1)
	{
		put_num((int)time.tv_usec);
		write(1, "\n", 1);
		usleep(1000000);
	}
	return (NULL);
}

// t_philo **make_phil(int	num_of_phil)
// {
	
// }

int	main(int argc, char **argv)
{
	int	i;
	pthread_t thread;

	i = 0;

	// * how to start a thead
	pthread_create(&thread, NULL, &thread_phil, NULL);
	usleep(1000000);
	pthread_create(&thread, NULL, &thread_phil, NULL);
	usleep(1000000);

	// pthread_mutex_t mutex_fork;

	// pthread_mutex_init(&mutex_fork, NULL);
	// pthread_mutex_destroy(&mutex_fork);
	// printf("%lu\n", sizeof(pthread_t));
	// usleep(1000000);

}