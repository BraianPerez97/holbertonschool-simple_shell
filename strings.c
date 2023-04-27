#include "main.h"

/**
  * _strcmp - compares two strings.
  * @s1: String parameter.
  * @s2: String parameter to compare.
  *
  * Description: Compares two strings by bytes.
  * Return: A positive value if s1 is greater than s2, a negative value if s1
  * is lesser and 0 if both are equal.
  */

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 < *s2)
			return (*s1 - *s2);
		if (*s1 > *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

/**
  * _strlen - returns the length of a string
  * @s: string parameter
  *
  * Description: Counts each byte of the string, and that counts the length
  * of the string.
  * Return: Length of a string.
  */

int _strlen(char *s)
{
	int i, count = 0;

	for (i = 0; s[i]; i++)
		count++;
	return (count);
}

/**
  * _strcat - concatenates two strings.
  * @dest: Destination string.
  * @src: String to add to end of dest.
  *
  * Description: Concatenates two strings. Appends the src string to the dest
  * string, overwriting the terminating null byte (\0) at the end of dest, and
  * then adds a terminating null byte.
  * Return: char pointer to dest.
  */

char *_strcat(char *dest, char *src)
{
	int count = 0;
	int src_count = 0;
	char *tmp = dest;
	char *tmp2 = src;

	while (*dest)
		dest++;
	while (*src++)
		src_count++;
	while (count < src_count)
	{
		*dest++ = *tmp2++;
		count++;
	}
	*dest = '\0';
	return (tmp);
}

/**
  * _strdup - returns a pointer to a newly allocated space in memory.
  * @str: String parameter.
  *
  * Return: returns a pointer to a new string which is a duplicate of the
  * string str, NULL if str is NULL or if dup is NULL.
  */

char *_strdup(char *str)
{
	char *dup;
	int i, j;

	if (str == NULL)
		return (NULL);

	for (j = 0; str[j] != '\0'; j++)
	{
	}

	j++;
	dup = malloc(sizeof(char) * j);

	if (dup == NULL)
		return (NULL);

	for (i = 0; i < j; i++)
		dup[i] = str[i];
	return (dup);
}

/**
  * _memcpy - copy memory area.
  * @dest: Destination adress.
  * @src: Source adress.
  * @n: Bytes to copy.
  *
  * Description: copies n bytes from memory area src to memory area dest.
  */

void _memcpy(void *dest, void *src, size_t n)
{
	char *cpsrc = src;
	char *cpdest = dest;
	size_t i;

	for (i = 0; i < n; i++)
		cpdest[i] = cpsrc[i];
}
