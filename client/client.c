#include "../includes/minitalk.h"
/*
	-- this is the client file --
* the client take two arguments
	* the server PID
	* the string want be send
* The client must send the string passed as a parameter to the server.
	* how this client cane do that >> by using signal :) 
	* you need to sent a sind two signal like morse code 1 or 0 (SIGUSR1 or SIGUSR2)
	* how i can do that again 
	>> ok i have a PID as a string i need to make it as an integer
	>> and i have message as a string i need to send it as morse code (SIGUSER1 or SIGUSER2)
	! i don't now if that work as fine i need to creat a server to test it
*/

void send_a_char(int pid, char c)
{
	int i;
	i = 0;
	while (i < 7)
	if (c & (1 << i++))
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

int main(int argc, char **argv)
{	
	int i;
	int pid;
	if (argc != 3)
	{
		return (write(0, " [PID] [Message want be send] \n", 31), 1);
	}
	i = 0;
	pid = atoi(argv[1]);
	while (argv[2][i])
	{
		send_a_char(pid, argv[2][i]);
	}
}