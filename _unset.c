#include "main.h"

/**
* unset - unsets an environment variable
* @name: the name of environment variable to set
*/

void unset(char *name)
{
	int i, j;

	if (name == NULL)
		return;
	i = 0;
	while (__environ[i] != NULL)
	{
		if (strncmp(__environ[i], name, strlen(name)) == 0)
		{
			free(__environ[i]);
			for (j = i; __environ[j] != NULL; j++)
				__environ[j] = __environ[j + 1];
		}
		i++;
	}
	__environ[i] = __environ[i + 1];
}
