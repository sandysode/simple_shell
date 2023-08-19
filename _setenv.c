#include "main.h"

/**
* _setenv - sets an environment variable in format "name=value"
* @name: the name of variable
* @value: the value to set name to
* Return: returns void
*/

void _setenv(char *name, char *value)
{
	int i;
	size_t nameLen, valueLen;

	if (name == NULL)
		return;
	nameLen = strlen(name);
	valueLen = strlen(value);
	for (i = 0; __environ[i] != NULL; i++)
	{
		if (strncmp(__environ[i], name, strlen(name)) == 0)
		{
			free(__environ[i]);
			__environ[i] = malloc(nameLen + valueLen);
			if (__environ[i] == NULL)
				return;
			strcpy(__environ[i], name);
			strcat(__environ[i], "=");
			strcat(__environ[i], value);
			return;
		}
	}
	__environ[i] = malloc(nameLen + valueLen + 2);
	if (__environ[i] == NULL)
		return;
	strcpy(__environ[i], name);
	strcat(__environ[i], "=");
	strcat(__environ[i], value);
	__environ[i + 1] = NULL;
}
