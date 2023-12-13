
# List of utility functions

## Development
1. print_string_array:
	```
	/**
	* print_string_array - Prints all strings in array
	* @arr: Array
	* @len: Length of array
	*/
	void print_string_array(char **arr, size_t len);
	```

## Memory Management
1. print_string_array:
	```
	/**
	* free_string_array - Frees an array of strings
	* @array: Array
	* @len: Length of the array to be freed
	*/
	void free_string_array(char **array, size_t len);
	```
2. _realloc
	```
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
	void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
	```

## Strings
1. _strlen:
Computes the length of a string

	```
	int _strlen(char *str);
	```
2. _strtok:
Splits a string into tokens separated by delimiter 

	```
	/**
	* _strtok - splits string into a sequence of zero or
	* more nonempty tokens.
	* @str: String pointer
	* @delim: String Delimiter
	*/
	char *_strtok(char *str, const char *delim);
	```
3. _strdup:
Duplicates a string

	```
	/**
	* _strdup - Duplicates a string
	* @s: String to be duplicated
	*
	* Return: Copy of string passed as argument
	*/
	char *_strdup(const char *s);
	```

## Path
1. get_cmd_path:
Returns the path of the command provided if it exists  
	```
	/**
	* get_cmd_path - Get exe path
	* @str: string input
	*
	* Return: full path of exe/cmd, NULL if it doesn't exist
	*/
	char *get_cmd_path(char *str);
	```



