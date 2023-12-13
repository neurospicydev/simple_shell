#include "shell.h"

/**
 * update_pwd_env - Update the PWD and OLDPWD environment variables
 */
void update_pwd_env(void)
{
	char cwd[PATH_MAX];

	/* Get the current working directory */
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd");
		return;
	}

	/* Update PWD and OLDPWD in the environment */
	_setenv("OLDPWD", _getenv("PWD"), true);
	_setenv("PWD", cwd, true);
}

/**
 * handle_cd_builtins_cmd - Handle the cd built-in command
 * @cmd: Command array
 * @token_count: Pointer to the token count
 *
 * Return: 0 (success), otherwise -1
 */
int handle_cd_builtins_cmd(char **cmd, int *token_count)
{
	char *path;

	if (*token_count == 1 || _strcmp(cmd[1], "~") == 0)
	{
		/* Change to home directory */
		path = _getenv("HOME");
	}
	else if (_strcmp(cmd[1], "-") == 0)
	{
		/* Change to the previous directory */
		path = _getenv("OLDPWD");
	}
	else
	{
		path = cmd[1];
	}

	if (chdir(path) != 0)
	{
		perror(cmd[0]);
		free_string_array(cmd, *token_count);
		*token_count = 0;
		return (-1);
	}

	/* Update PWD and OLDPWD in the environment */
	update_pwd_env();
	free_string_array(cmd, *token_count);
	*token_count = 0;
	return (0);
}
