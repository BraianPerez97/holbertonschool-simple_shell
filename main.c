#include "main.h"

/**
 * main - start point
 * @ac: counter
 * @av: vector
 * Return: 0 if succesful
 */

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	/* declaring variables */
	char *prompt = "(Shelly) $";
	size_t size = 0;
	char *obt_line;
	
	/*start of code*/
	printf("%s", prompt);
	getline(&obt_line, &size, stdin);
	print("%s\n", obt_line);

	free(obt_line);
	return(0);
{
