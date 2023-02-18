/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:58:28 by sboulain          #+#    #+#             */
/*   Updated: 2023/02/18 19:52:35 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

//for write/ usleep
# include <unistd.h>
//for the thread things
# include <pthread.h>
//for printf
# include <stdio.h>
//for malloc
# include <stdlib.h>
//for bool
# include <stdbool.h>
//for gettimeofday
# include <sys/time.h>

void	put_num(int num);

typedef struct s_philo
{
	int				num_time_eat;
	int				num_of_phil;
	bool			*start;
	bool			alive;
	pthread_t		*current_thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*write_on_terminal;

}	t_philo;

#endif