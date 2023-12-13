#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _realloc_buffer - Resize the buffer if needed.
 *
 * @lineptr: Pointer to the buffer where the line will be stored.
 * @n: Pointer to the size of the buffer.
 *
 * Return: 0 on success, -1 on failure.
 */
int _realloc_buffer(char **lineptr, size_t *n)
{
	size_t new_size = *n * 2, i = 0; /* Double the buffer size */
	char *new_lineptr = (char *)malloc(new_size);

	/* Memory allocation failure */
	if (new_lineptr == NULL)
		return (-1);

	for (i = 0; i < *n; ++i)
		new_lineptr[i] = (*lineptr)[i];

	free(*lineptr);
	*lineptr = new_lineptr;
	*n = new_size;

	return (0);
}

/**
 * read_line_until_newline - Read characters until newline or end of file.
 *
 * @lineptr: Pointer to the buffer where the line will be stored.
 * @n: Pointer to the size of the buffer.
 *
 * Return: Number of characters read (including the newline character),
 *         or -1 if an error occurs or end of file is reached.
 */
ssize_t read_line_until_newline(char **lineptr, size_t *n)
{
	char buffer[1024];
	ssize_t chars_read, j;
	size_t i = 0;

	while ((chars_read = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
	{
		for (j = 0; j < chars_read; ++j)
		{
			if (i >= *n - 1 && _realloc_buffer(lineptr, n) == -1)
				return (-1);

			(*lineptr)[i++] = buffer[j];

			if (buffer[j] == '\n')
			{
				(*lineptr)[i] = '\0';
				return (i);
			}
		}
	}

	return ((chars_read == 0 && i == 0) ? -1 : -1);
}

/**
 * _getline - Read a line from standard input.
 *
 * @lineptr: Pointer to the buffer where the line will be stored.
 * @n: Pointer to the size of the buffer.
 *
 * Return: Number of characters read (including the newline character),
 *         or -1 if an error occurs or end of file is reached.
 */
ssize_t _getline(char **lineptr, size_t *n)
{
	/* Invalid arguments */
	if (lineptr == NULL || n == NULL)
		return (-1);

	/* Allocate initial buffer if not provided */
	if (*lineptr == NULL || *n == 0)
	{
		/* Initial buffer size */
		*n = 1024;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}

	return (read_line_until_newline(lineptr, n));
}
