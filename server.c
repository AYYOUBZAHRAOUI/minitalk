/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzahrao <ayzahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:34:47 by ayzahrao          #+#    #+#             */
/*   Updated: 2024/09/14 22:07:06 by ayzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

//	print integers
static void	putint(int pid)
{
	if (pid / 10)
		putint(pid / 10);
	write(1, ("0123456789") + (pid % 10), 1);
}

//	print pid of the server
static void	print_pid(int pid)
{
	write(1, "--------- SERVER PID ", 21);
	putint(pid);
	write(1, " ---------\n", 11);
}

// signal handler
static void	signal_handler(int x, siginfo_t *info, void *param)
{
	static char	c;
	static int	bit_position;
	static int	pid;

	(void)param;
	if (pid != info->si_pid)
	{
		bit_position = 0;
		c = 0;
	}
	pid = info->si_pid;
	if (x == SIGUSR1)
		c = c | (1 << bit_position);
	bit_position++;
	if (bit_position == 8)
	{
		bit_position = 0;
		write(1, &c, 1);
		c = 0;
	}
}

// main function
int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(write(2, "sigaction error \n", 17));
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(write(2, "sigaction error \n", 17));
	print_pid(getpid());
	while (1)
		;
	return (0);
}
