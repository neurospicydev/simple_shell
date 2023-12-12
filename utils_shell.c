#include "shell.h"

/**
 * build_cmd_array - Builds the cmd array for execve
 * @line: Line returned by getline
 * @token_count: Pointer to the token count
 *
 * Return: NULL termineated array of strings for execve
 */
char **build_cmd_array(char *line, int *token_count)
{
	char *token, *delim = " ";
	char **cmd = NULL;

	token = _strtok(line, delim);

	while (token != NULL)
	{
		cmd = _realloc(cmd,
					   *token_count * sizeof(char *),
					   (*token_count + 1) * sizeof(char *));

		cmd[*token_count] = malloc(strlen(token) + 1);
		/* Handle failure and clean all memory */

		strcpy(cmd[*token_count], token);

		/* Free token before the next _strtok call */
		free(token);

		token = _strtok(NULL, delim);
		(*token_count)++;
	}

	if (cmd != NULL)
	{
		/* Allocate memory for the null byte */
		cmd = _realloc(cmd,
					   *token_count * sizeof(char *),
					   (*token_count + 1) * sizeof(char *));
		cmd[(*token_count)++] = NULL;
	}

	return (cmd);
}

/**
 * preprocess_cmd - Preprocesses command array
 * @program_name: Program name
 * @cmd: Command array, null terminated
 * @token_count: Pointer to the token count
 *
 * Return: 0(sucess), an interger if error
 */
int preprocess_cmd(char *program_name, char **cmd, int *token_count)
{
	char *path;

	if (cmd == NULL || *cmd == NULL)
		return (0);

	path = get_cmd_path(*cmd);

	if (!is_existing_path(path))
	{
		write(STDERR_FILENO, program_name, _strlen(program_name));
		write(STDERR_FILENO, ": ", _strlen(": "));
		write(STDERR_FILENO, NOT_FOUND, _strlen(NOT_FOUND));
		free(path);
		free_string_array(cmd, *token_count);
		*token_count = 0;
		return (127);
	}

	free(path);

	return (0);
}

/**
 * handle_cmd - Handles the cmd execution
 * @program_name: Program name
 * @cmd: Command array, null terminated
 * @token_count: Pointer to the token count
 *
 * Return: 0(sucess), an interger if error
 */
int handle_cmd(char *program_name, char **cmd, int *token_count)
{
	pid_t shell_pid;

	if (cmd == NULL)
		return (0);

	shell_pid = fork();

	/* Child process */
	if (shell_pid == 0 && execve(get_cmd_path(*cmd), cmd, environ) == -1)
	{
		if (cmd)
		{
			free_string_array(cmd, *token_count);
			*token_count = 0;
		}
		perror(program_name);
		return (-1);
	}
	else if (shell_pid > 0)
	{

		/* Parent process */
		if (cmd)
		{
			free_string_array(cmd, *token_count);
			*token_count = 0;
		}
	}

	return (0);
}
