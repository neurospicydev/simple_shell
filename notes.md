# Notes

## Strtok function
```
#include "main.h"
#include <stdlib.h>

/**
 * _strtok - splits string into a sequence of zero or
 * more nonempty tokens.
 * @str: String pointer
 * @delim: String Delimiter
 */
char *_strtok(char *str, const char *delim)
{

	static char *input;

	char *token;
	size_t token_len = 0, i;

	/* If a new string is provided, update the input pointer */
	input = str ? str : input;

	/* Skip leading delimiters */
	if (input[token_len] == *delim)
		input++;

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
```

## Avoiding memory leaks
1. Always remember to free the char pointer line as it will always be dynamically allocated by the getline function as you can see below:

```
/**
 * main - Super Simple shell
 *
 */
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *line;
	size_t len;
	ssize_t bytes_read;

	while ((bytes_read = getline(&line, &len, stdin)) != -1)
	{
		printf("%s", line);
		if (strcmp(line, "exit\n") == 0)
		{
			break;
		}
	}

	free(line);

	return (0);
}

```