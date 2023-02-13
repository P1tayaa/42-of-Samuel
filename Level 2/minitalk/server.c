/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:21:06 by sboulain          #+#    #+#             */
/*   Updated: 2023/02/13 17:15:12 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "mega_libft/libft.h"

static void What_he_do(int sig, siginfo_t *info, void *context)
{
	static unsigned int		number_byte_transfered = 0;
	static unsigned char	char_getting = 0;
	pid_t					my_pid;
	
	(void)context;
	my_pid = info -> si_pid;
	if (sig == SIGUSR2)
	{
		char_getting = (1 == 1) | char_getting;
		// if (number_byte_transfered != 8)
		// 	char_getting <<= 1;
	}
	// else
	// if (sig == SIGUSR1)
	// {
	// 	char_getting = (1 == 0);
	// 	if (number_byte_transfered != 8)
	// 		char_getting <<= 1;
	// }
	
	// char_getting = (sig == SIGUSR2);
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

	// ft_printf("conect BY pid: %d", my_pid);
	// ft_printf("conect BY sig: %d\n", sig);

}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_printf("test");
	ft_printf("this is pid: %d\n", getpid());

	s_sigaction.sa_sigaction = What_he_do;
	s_sigaction.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();

	return (1);
}


// static void	action(int sig, siginfo_t *info, void *context)
// {
// 	static int				i = 0;
// 	static pid_t			client_pid = 0;
// 	static unsigned char	c = 0;

// 	(void)context;
// 	if (!client_pid)
// 		client_pid = info->si_pid;
// 	c |= (sig == SIGUSR2);
// 	if (++i == 8)
// 	{
// 		i = 0;
// 		if (!c)
// 		{
// 			kill(client_pid, SIGUSR2);
// 			client_pid = 0;
// 			return ;
// 		}
// 		ft_putchar_fd(c, 1);
// 		c = 0;
// 		kill(client_pid, SIGUSR1);
// 	}
// 	else
// 		c <<= 1;
// }

// int	main(void)
// {
// 	struct sigaction	s_sigaction;

// 	ft_putstr_fd("Server PID: ", 1);
// 	ft_putnbr_fd(getpid(), 1);
// 	ft_putchar_fd('\n', 1);
// 	s_sigaction.sa_sigaction = action;
// 	s_sigaction.sa_flags = SA_SIGINFO;
// 	sigaction(SIGUSR1, &s_sigaction, 0);
// 	sigaction(SIGUSR2, &s_sigaction, 0);
// 	while (1)
// 		pause();
// 	return (0);
// }