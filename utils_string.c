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

	while (s && s[len] != '\0') /* null terminator in C */
		len++;

	return (len); /* return the length of the string */
}

/**
 * _strcat - Concatenates two strings.
 *
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 *
 * Return: Pointer to the destination string.
 *
 * Description: This function appends the content of the 'src'
 * string to the end of the 'dest' string, overwriting the null
 * terminator at the end of 'dest'. The resulting concatenated
 * string is returned as the result.
 */

char *_strcat(char *dest, char *src)
{
	int dest_len = _strlen(dest), i = 0;

	if (dest == NULL || src == NULL)
		return (dest);

	for (; src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];

	dest[dest_len + i] = '\0';

	return (dest);
}
