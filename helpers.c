#include "shell.h"


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

/**
* _strcpy - A function that copies the string pointed
* to by src,including the terminating null byte \0
* to the buffer pointed to by dest.
* @dest: Pointer variable of type char, destination of copy
* @src: Pointer variable of type char, source of copy
*
* Return: The pointer to dest.
*/

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	for (; src[i]; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
