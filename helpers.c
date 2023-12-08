#include "shell.h"

/**
 * _strlen - A function that returns the length of a string.
 * @s: string parameter of type char.
 *
 * Return: Always 0 (Success)
 */

int _strlen(const char *s)
{
	int len = 0;

	while (*s != '\0') /* null terminator in C */
	{
		len++;
		s++;
	}
	return (len); /* retun the length of the string */
}

/**
 * _strncmp - A function that compares two strings
 * @s1: first pointer parameter of type char
 * @s2: second pointer parameter of type char
 * @n: number of characters to compare
 *
 * Return: Always 0 (Success)
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && n > 0)
	{
		if (*s1 != *s2)
		{
			break;
		}
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);

	/* return ascii difference after converting *char to unsigned *char */
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
