#include "shell.h"

/**
 * is_cmd - this determine if a file is an executable command
 * @info: info struct
 * @path: the path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - the duplicate characters
 * @pathstr: PATH string
 * @start: the starting index
 * @stop: helps to stop the index
 *
 * Return: the pointer to new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int y = 0, z = 0;

	for (z = 0, y = start; y < stop; y++)
		if (pathstr[y] != ':')
			buf[z++] = pathstr[y];
	buf[z] = 0;
	return (buf);
}

/**
 * find_path - helps to find this cmd in the PATH string
 * @info: info struct
 * @pathstr: PATH string
 * @cmd: cmd to find
 *
 * Return: the full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int k = 0, curr_index = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[k] || pathstr[k] == ':')
		{
			path = dup_chars(pathstr, curr_index, k);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[k])
				break;
			curr_index = k;
		}
		k++;
	}
	return (NULL);
}
