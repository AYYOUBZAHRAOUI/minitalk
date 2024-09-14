/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzahrao <ayzahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:34:41 by ayzahrao          #+#    #+#             */
/*   Updated: 2024/09/14 00:39:30 by ayzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void send_a_char(int pid, char c)
{
	int i;
	i = 0;
	while (i <= 7)
	{
		if (c & (1 << i++))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

int main(int argc, char **argv)
{	
	int i;
	int pid;
	if (argc != 3)
	{
		return (write(0, " [PID] [Message want be send] \n", 31));
	}
	i = 0;
	pid = atoi(argv[1]);
	// printf("this PID is %i\n", pid);
	while (argv[2][i])
	{
		send_a_char(pid, argv[2][i]);
		i++;
	}
}