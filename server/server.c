#include "../includes/minitalk.h"
/*
	-- the server file --
// the server print PID
// the server wile receive a signals SIGUSER1 SIGUSER2
* how to receive a signal >> use signal function
* how to 
*/

void signal_handler(int x)
{
	if ()
}


int main(void)
{
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	printf("PID OF the SERVER IS :%i\n", getpid());
	return(0);
}