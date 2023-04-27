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
		isatty(STDIN_FILENO) == 1 ? write(1, "$ ", 2) : 0;
		f = getline(&buf, &bufsize, stdin); /* user input line */
		if (f == -1)
		{
			free(buf);
			return (status); }
		if (_strcmp(buf, "\n") == 0) /* if only newline is passed */
		{
			free(buf), buf = NULL;
			continue; }
		buf[f - 1] = '\0', argv = malloc(sizeof(char *)); /* replaces \n for \0 */
		if (argv == NULL)
		{
			free(buf);
			return (status); }
		dup = _strdup(buf), token = strtok(dup, " \t"), argv[0] = token;
		if (argv[0] == NULL || token == NULL) /* Above tokenize the first argument */
		{
			free(argv), free(dup);
			continue; }
		for (i = 1; token; i++) /* Continues to tokenize */
		{ /* Each token is part of the line using space or tab as delimiters */
			token = strtok(NULL, " \t");
			argv = _realloc(argv, i * sizeof(char *), (i + 1) * sizeof(char *));
			argv[i] = token; }
		argv = _realloc(argv, i * sizeof(char *), (i + 1) * sizeof(char *));
		argv[i] = NULL;
		if (_strcmp(argv[0], "env") == 0 && !argv[1]) /* env built-in */
		{
			free(argv), free(dup), _printenv();
			continue; }
		if (_strcmp(argv[0], "exit") == 0 && !argv[1]) /* exit built-in */
			free(argv), free(dup), free(buf), exit(status);
		status = executor(argv, inputptr), free(dup); } /* Execute command */
	return (status); } /* or prints error message if not found */
