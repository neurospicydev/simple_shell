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

	token = get_cmd_path(_strtok(line, delim));

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
	if (shell_pid == 0 && execve(cmd[0], cmd, environ) == -1)
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
