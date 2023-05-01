/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:21:06 by sboulain          #+#    #+#             */
/*   Updated: 2023/04/29 16:45:28 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "mega_libft/libft.h"

static void	check_if_received(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (sig == SIGUSR2)
		ft_printf("Message received");
	exit(1);
}

void	send_char_one_byte_at_a_time(int pid, char char_sending)
{
	int	i;

	i = 8;
	while (i)
	{
		i--;
		if (char_sending >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

void	send_message(int pid, char *message)
{
	int		j;
	char	char_sending;

	j = 0;
	while (message[j] != '\0')
	{
		char_sending = message[j];
		send_char_one_byte_at_a_time(pid, message[j]);
		j++;
	}
	send_char_one_byte_at_a_time(pid, '\0');
}

int	main(int argc, char **argv)
{
	struct sigaction	s_sigaction;
	int					pid;

	if (argc != 3)
		return (1);
	s_sigaction.sa_sigaction = check_if_received;
	sigaction(SIGUSR2, &s_sigaction, 0);
	pid = ft_atoi(argv[1]);
	if (pid < 0)
		return (1);
	send_message(pid, argv[2]);
	while (1)
		pause();
	return (1);
}
