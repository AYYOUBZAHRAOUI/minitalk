/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzahrao <ayzahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:34:47 by ayzahrao          #+#    #+#             */
/*   Updated: 2024/09/14 00:45:16 by ayzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
/*
	-- the server file --
// the server print PID
// the server wile receive a signals SIGUSER1 SIGUSER2
* how to receive a signal >> use signal function
* how to 
*/

void signal_handler(int x, int pidclient)
{
	static char c = 0 ;
	static int bit_position;
	static pid;
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


int main(void)
{
	sigaction(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	printf("PID OF the SERVER IS :%i\n", getpid());
	while (1);
	return(0);
}