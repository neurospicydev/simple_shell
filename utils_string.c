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

/**
 * _strtok - splits string into a sequence of zero or
 * more nonempty tokens.
 * @str: String pointer
 * @delim: String Delimiter
 *
 * Return: string token
 */
char *_strtok(char *str, const char *delim)
{
	static char *input;
	char *token;
	size_t token_len = 0, i;

	/* If a new string is provided, update the input pointer */
	input = str ? str : input;

	/* Skip leading delimiters */
	while (*input == *delim)
	{
		input++;
		*(input - 1) = '\0';
	}

	/* No more tokens */
	if (input == NULL || *input == '\0')
		return (NULL);

	/*compute len of token*/
	while (input[token_len] != '\0' &&
		   input[token_len] != *delim && input[token_len] != '\0')
		token_len++;

	token = (char *)malloc((token_len + 1) * sizeof(char));

	/* Handle memory allocation failure */
	if (token == NULL)
		return (NULL);

	/* Copy the token characters */
	for (i = 0; i < token_len; i++)
		token[i] = input[i];

	/* Add null terminator */
	token[token_len] = '\0';

	/* Add null terminator */
	input += token_len;

	return (token);
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
