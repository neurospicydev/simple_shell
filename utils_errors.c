#include "shell.h"

/**
 * err_invalid_argc - Prints error to indicate invalid number of arguments
 * @process_name: Process name
 * @status: Status
 */
void err_invalid_argc(char *process_name, int *status)
{
	char *error_message = ": invalid number of arguments\n";

	write(STDERR_FILENO, process_name, _strlen(process_name));
	write(STDERR_FILENO, error_message, _strlen(error_message));
	*status = -1;
}
