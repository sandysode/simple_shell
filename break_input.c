#include "main.h"

/**
* brkdown_args - splits arguments with _strtok()
* @buffer: the array of arguments
* Return: 0 if failed
*/
int brkdown_args(char *buffer)
{
	char *temp;
	char **args;
	int i;

	args = malloc(strlen(buffer) + 1 + sizeof(char));
	temp = malloc(strlen(buffer));
	if (args == NULL || temp == NULL)
	{
		free(args);
		free(temp);
		exit(98);
	}
	i = 0;
	temp = _strtok(buffer, " ");
	while (temp != NULL)
	{
		args[i] = temp;
		temp = _strtok(NULL, " ");
		i++;
	}
	free(temp);
	execute_file(args, i);
	return (0);
}
