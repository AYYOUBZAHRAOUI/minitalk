/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzahrao <ayzahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:34:41 by ayzahrao          #+#    #+#             */
/*   Updated: 2024/09/14 22:32:04 by ayzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

// convert string to integer
static int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	x;

	x = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		x = x * 10 + (str[i++] - '0');
	}
	return (x * sign);
}

// send a char to the server
static void	send_a_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		if (c & (1 << i++))
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(write(2, "kill error 1\n", 13));
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(write(2, "kill error 2\n", 13));
		}
		usleep(100);
	}
}

// main function
int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc != 3)
	{
		write(2, "ERROR you hate to put two argument [PID] [MESSAGE] \n", 44);
		return (1);
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		send_a_char(pid, argv[2][i]);
		i++;
	}
}
