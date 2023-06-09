#include "shell.h"

/**
 * _myexit - This exits the shell
 * @info: Holds the Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: This exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int checkexit;

	if (info->argv[1])  /* Check If there is an exit arguement */
	{
		checkexit = _erratoi(info->argv[1]);
		if (checkexit == -1)
		{
			info->status = 2;
			print_error(info, "Invalid number input: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - This changes the current directory of the process
 * @info: Represent the Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int ret_chdir;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failed at this point<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			ret_chdir = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			ret_chdir = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		ret_chdir = /* TODO: what should this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		ret_chdir = chdir(info->argv[1]);
	if (ret_chdir == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - This changes the current directory of the process
 * @info: Represent the Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
