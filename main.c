#include "main.h"

/**
 * main - start point
 * @ac: counter
 * @av: vector
 * Return: 0 if succesful
 */

int main(int ac, char **argv)
{
	char *prompt = "~/Shelly $ ";
	size_t size = 0;
	char *obt_line;
	ssize_t nchars_read;

	/* declaring void variables */
	(void)ac; (void)argv;
	/* creating infinite loop */
	while (1)
	{
		printf("%s", prompt);
		nchars_read = getline(&obt_line, &size, stdin);
		if (nchars_read == -1)
		{
		/* exiting shell prompt */ 
		printf("Exiting shell.\n");
		return(-1);
		}
		printf("%s\n", obt_line);
	}
	/* free allocated memory */
	free(obt_line);
	return(0);
}
