#include "main.h"
#include <string.h>

/**
  * _realloc - reallocates a memory block using malloc and free.
  * @ptr: Pointer to the memory previously allocated with malloc(old_size).
  * @oldSize: Size in bytes of the allocated space for ptr.
  * @newSize: New size in bytes of the new memory block.
  *
  * Return: If new_size is 0, returns NULL, if ptr is NULL returns allocated
  * memory of size newSize or if newSize is bigger than oldSize retuns ptr.
  * Otherwise, returns ptr.
  */

void *_realloc(void *ptr, size_t oldSize, size_t newSize)
{
	void *newptr = malloc(newSize);

	if (newSize == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (!ptr)
	{
		return (malloc(newSize));
	}
	else if (newSize <= oldSize)
	{
		return (ptr);
	}
	else
	{
		if (newptr)
		{
			_memcpy(newptr, ptr, oldSize);
			free(ptr);
		}
		return (newptr);
	}
}

/**
  * pathfinder - handle the PATH for the given command name.
  * @str: Command name string.
  *
  * Return: The entire PATH of str if it exists, str if not.
  */

char *pathfinder(char *str)
{
	char *PATHvalue = _getenv("PATH"), *PATHdup = _strdup(PATHvalue);
	char *token, *dup = NULL;
	struct stat st;

	if (PATHvalue != NULL)
		free(PATHvalue - 5);
	else
		return (str);
	token = strtok(PATHdup, ":");
	 /* _getenv moved the pointer five blocks in the */
			/* allocated memory, so we subtract that five */
	while (token) /* Each token is a part of the value of PATH using ':' as a */
		/* delimiter */
	{
		dup = _strdup(token);
		dup = _realloc(dup, _strlen(dup) + 1, _strlen(dup) + 2);
		_strcat(dup, "/");
		dup = _realloc(dup, _strlen(dup) + 1, _strlen(dup) + 1 + _strlen(str));
		_strcat(dup, str); /* With duplicates, we concatenate the value with the */
		/* str given */
		if (stat(dup, &st) == 0) /* Check if the command is found */
		{
			free(PATHdup);
			return (dup);
		}
		token = strtok(NULL, ":");
		free(dup);
	}
	free(PATHdup);
	return (str);
}

/**
  * _getenv - Get an environment variable value by its name.
  * @name: name of the environment variable to find.
  *
  * Return: The environment variable value, NULL otherwise.
  */

char *_getenv(const char *name)
{
	int i;
	char *dup;

	for (i = 0; environ[i]; i++)
	{
		dup = _strdup(environ[i]);
		strtok(dup, "=");
		if (_strcmp(dup, name) == 0)
		{
			if (*(dup + 5) == '\0')
			{
				free(dup);
				return (NULL);
			}
			dup = strtok(NULL, "=");
			return (dup);
		}
		free(dup);
	}
	return (NULL);
}

/**
  * executor - executes the given command or prints error in other case.
  * @argv: Array of strings with the input given.
  * @inputs: Pointer to the counter of lines passed.
  *
  * Return: 0 if it works, -1 otherwise.
  */

int executor(char **argv, size_t *inputs)
{
	char *finder;
	struct stat st;
	DIR *d = opendir(".");

	if (find_file(argv[0], d) != 0)
	{
		closedir(d);
		if (stat(argv[0], &st) == 0)
			return (forker(argv[0], argv, inputs));
		finder = pathfinder(argv[0]);
		if (stat(finder, &st) == 0) /* Check if the command exists */
			return (forker(finder, argv, inputs));
	}
	else
		closedir(d);
	/* if command not found */
	fprintf(stderr, "./hsh: %ld: %s: not found\n", *inputs, argv[0]);
	/* The error message depends on the number of */
	/* input lines given thus far, and the not found command */
	free(argv);
	return (127); /* 127 is the status code for exit when command not found */
}

/**
  * _printenv - prints all environment variables.
  *
  */

void _printenv(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
}
