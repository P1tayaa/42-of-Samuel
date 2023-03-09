/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:21:06 by sboulain          #+#    #+#             */
/*   Updated: 2023/03/08 17:56:45 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "mega_libft/libft.h"

static void	what_he_do(int sig, siginfo_t *info, void *context)
{
	static unsigned int		number_byte_transfered = 0;
	static unsigned char	char_getting = 0;
	pid_t					my_pid;

	(void)context;
	my_pid = info -> si_pid;
	if (sig == SIGUSR2)
		char_getting = (1 == 1) | char_getting;
	if (++number_byte_transfered == 8)
	{
		number_byte_transfered = 0;
		if (char_getting == '\0')
		{
			kill(my_pid, SIGUSR2);
			char_getting = 0;
			ft_putchar('\n');
			return ;
		}
		ft_putchar(char_getting);
		char_getting = 0;
	}
	else
		char_getting <<= 1;
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_printf("test");
	ft_printf("this is pid: %d\n", getpid());

	s_sigaction.sa_sigaction = what_he_do;
	s_sigaction.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();

	return (1);
}
