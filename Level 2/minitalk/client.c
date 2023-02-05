/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:21:06 by sboulain          #+#    #+#             */
/*   Updated: 2023/02/05 16:30:25 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "mega_libft/libft.h"

static void check_if_received(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGUSR2)
		ft_printf("Message received");
	exit(1);
}

void	send_message(int pid, char *message)
{
	int		i;
	int		j;
	char	char_sending;

	j = 0;
	while (message[j] != '\0')
	{
		i = 8;
		char_sending = message[j];
		while (i)
		{
			i--;
			if (char_sending >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
		j++;
	}
	i = 8;
	char_sending = '\0';
	while (i--)
	{
		if (char_sending >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
	
		// char_sending <<= 1;

	// kill(pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	s_sigaction;

	if (argc != 3)
		return (1);
	s_sigaction.sa_sigaction = check_if_received;
	// sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	// ft_printf("%s/n",argv[2]);
	send_message(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();

	return (1);
}
