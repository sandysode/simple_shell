#include "main.h"

/**
* checkargs - this check arguments passed
* @arg: number of args passed
* @ac: array of args
* @exe: for executable
* Return: returns pointer to stdin
*/
int checkargs(int arg, char **ac, int *exe)
{
	int temp = STDIN_FILENO;
	char *error = "Error: more than one argument\n";

	if (arg > 2)
	{
		write(STDOUT_FILENO, error, strlen(error));
	}
	/*Handle executable files if any e.g "./a.out /bin/ls" */
	if (arg == 2)
	{
		temp = open(ac[1], O_RDONLY);
		*exe = 1;
	}
	if (temp == -1)
	{
		perror(ac[0]);
	}
	return (temp);
}
