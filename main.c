#include "main.h"

/**
 * main - start point
 * @ac: counter
 * @av: vector
 * Return: 0 if succesful
 */

int main(int ac, char **argv)
{
	/* declaring variables */
	char *prompt = "(Shelly) $";
	size_t size = 0;
	char *obt_line;

	/* creating an infinite loop */
	(void)ac; (void)argv;
	/*start of code*/
	while (1)
	{
		printf("%s", prompt);
		getline(&obt_line, &size, stdin);
		printf("%s\n", obt_line);

	}
	free(obt_line);
	return(0);
}
