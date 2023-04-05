/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:58:28 by sboulain          #+#    #+#             */
/*   Updated: 2023/03/14 19:57:19 by sboulain         ###   ########.fr       */
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
//for printf
#include <stdio.h>


void	put_num(int num);

void	put_num_64(uint64_t num);

bool	ft_atoi(char *str, int *number);

int	put_str(char *str);

typedef struct s_philo
{
	int				num_time_eat;
	int				num_of_phil;
	bool			*start;
	bool			alive;
	pthread_t		*current_thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

}	t_philo;

typedef struct s_args_info
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
	bool	all_good;
}	t_args_info;

typedef struct s_args_info_plus_philo
{
	t_philo		*philo;
	t_args_info	arg_info;
}t_args_info_plus_philo;
#endif