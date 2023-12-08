#include "shell.h"

/**
 * print_string_array - Prints all strings in array
 * @arr: Array
 * @len: Length of array
 */
void print_string_array(char **arr, size_t len)
{
	size_t i = 0;

	for (i = 0; i < len; i++)
		printf("%lu - %s\n", i, arr[i]);
}
