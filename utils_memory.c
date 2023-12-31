#include "shell.h"

/**
 * free_string_array - Frees an array of strings
 * @array: Array
 * @len: Length of the array to be freed
 */
void free_string_array(char **array, size_t len)
{
	size_t i = 0;

	if (!array)
		return;

	for (; i < len; i++)
		free(array[i]);
	free(array);
	array = NULL;
}

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: size, in bytes, of the allocated space for ptr
 * @new_size: new size, in bytes of the new memory block
 *
 * Return: Pointer to the memory address of new pointer with size new_size
 *
 * - If new_size > old_size, the “added” memory should not be initialized
 * - If new_size == old_size do not do anything and return ptr
 * - If ptr is NULL, then the call is equivalent to malloc(new_size),
 * for all values of old_size and new_size
 * - If new_size is equal to zero, and ptr is not NULL, then the call is
 * equivalent to free(ptr). Return NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	int *newptr;
	size_t i;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		newptr = malloc(new_size);
		if (newptr == NULL)
			return (NULL);
		return (newptr);
	}

	newptr = malloc(new_size);
	if (newptr == NULL)
	{
		/* Free the original memory block */
		free(ptr);
		return (NULL);
	}

	/* Copy old data to newptr */
	for (i = 0; i < old_size; i++)
		*((char *)newptr + i) = *((char *)ptr + i);

	free(ptr);

	return (newptr);
}

/**
 * _memset - fills memory with a constant byte
 * @s: memory area pointed to by s
 * @b: constant byte
 * @n: number of bytes to fill
 * Return: char *s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	if (n <= 0)
		return (s);

	for (; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
