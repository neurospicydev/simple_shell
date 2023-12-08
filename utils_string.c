#include "shell.h"

/**
 * _strlen - Computes the length of a string
 * @str: String pointer
 *
 * Return: int, length of srtring
 */
int _strlen(char *str)
{
	int len = 0;

	while (str != NULL && str[len] != '\0')
		len++;

	return (len);
}

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
