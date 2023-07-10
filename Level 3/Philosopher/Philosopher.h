/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:58:28 by sboulain          #+#    #+#             */
/*   Updated: 2023/07/10 12:13:21 by sboulain         ###   ########.fr       */
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


char	*itoa(int num);

char	*put_num_64(uint64_t num);

bool	ft_atoi(char *str, int *number);

void	put_str(char *str);

char	*strdup(const char *s);

char	*str_join_and_free(char *str1, char *str2);

uint64_t	get_time();

typedef struct s_philo
{
	int				num_time_eat;
	int				num_of_phil;
	bool			*start;
	uint64_t		time_sinse_last_meal;
	uint64_t		start_time;
	pthread_t		*current_thread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	printf;
	
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
	uint64_t		start_time;
	
}t_args_info_plus_philo;
#endif