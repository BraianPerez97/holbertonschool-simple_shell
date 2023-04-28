#include "main.h"

/**
 * main - simple UNIX interpreter
 *
 * Return: -1 if failure, 0 otherwise.
 */

int main(void)
{
	size_t bufsize = 0, i, inputs = 1, *inputptr = &inputs, status = 0;
	ssize_t f;
	char *buf = NULL, *token, *dup, **argv;

	for (; 1; inputs++) /* Infinite loop which counts input lines */
	{
		/* cheks if the program is being executed in terminal */
		isatty(STDIN_FILENO) == 1 ? write(1, "$ ", 2) : 0;
		/* read user input */
		f = getline(&buf, &bufsize, stdin);
		/* handles case where getline returns -1)*/
		if (f == -1)
		{
			free(buf);
			return (status); 
		}
		/* handles if only newline is passed */
		if (_strcmp(buf, "\n") == 0)
		{
			free(buf), buf = NULL;
			continue; 
		}
		/* replace newline character with a null terminator */
		buf[f - 1] = '\0';
	       /* allocate memory for the first argument of the command */	
		argv = malloc(sizeof(char *));
		/* handles the case where malloc returns NULL */
		if (argv == NULL)
		{
			free(buf);
			return (status); 
		}
		/* duplicate the input line */
		dup = _strdup(buf);
		/* tokenize the first argument of the command */
		token = strtok(dup, " \t");
	       	argv[0] = token;
		/* handles case where the first argument is empty */ 
		if (argv[0] == NULL || token == NULL)
		{
			free(argv), free(dup);
			continue; 
		}
		/* tokenize the rest of command argument */
		for (i = 1; token; i++)
		{
			token = strtok(NULL, " \t");
			argv = _realloc(argv, i * sizeof(char *), (i + 1) * sizeof(char *));
			argv[i] = token; 
		}
		/* allocate memory of the NULL terminator at the end of argument */
		argv = _realloc(argv, i * sizeof(char *), (i + 1) * sizeof(char *));
		argv[i] = NULL;
		if (_strcmp(argv[0], "env") == 0 && !argv[1]) /* env built-in */
		{
			free(argv), free(dup), _printenv();
			continue; 
		}
		if (_strcmp(argv[0], "exit") == 0 && !argv[1]) /* exit built-in */
			free(argv), free(dup), free(buf), exit(status);
		/* execute the command or print error */
		status = executor(argv, inputptr);
	       	free(dup);
	}
	return (status);
}
