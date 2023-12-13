#include "shell.h"

/**
 * _strdup - Duplicates a string
 * @s: String to be duplicated
 *
 * Return: Copy of string passed as argument
 */
char *_strdup(const char *s)
{
	int len = 0, i;
	char *copy;

	len = _strlen(s);
	copy = malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		copy[i] = s[i];

	copy[len] = '\0';

	return (copy);
}

/**
 * _strcmp - Compare two strings.
 *
 * @s1: First string.
 * @s2: Second string.
 *
 * Return:
 *   0 if the strings are equal,
 *   < 0 if s1 is less than s2,
 *   > 0 if s1 is greater than s2.
 */

int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;

	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
