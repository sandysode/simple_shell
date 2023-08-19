#include "main.h"

/**
* main -Entry point
* @arg: number of argument
* @av: array of arguments
* Return: always 0
*/

int main(int arg, char **av)
{
	ssize_t get;
	size_t buff_size;
	int exe, fd;
	char *buffer = NULL;

	buff_size = 0;
	exe = 0;
	fd = checkargs(arg, av, &exe);
	while (1)
	{
		/*Write $ to STDIN*/
		write(STDOUT_FILENO, "$ ", 2);
		/*Get STDIN from STDIN*/
		get = getline(&buffer, &buff_size, stdin);
		if (get == EOF)
		{
			exit(98);
			return (0);
		}
		buffer = handle_comment(buffer);
		_strtok(buffer, "\n");
		brkdown_args(buffer);
	}
	free(buffer);
	if (exe)
		close(fd);
	return (0);
}
