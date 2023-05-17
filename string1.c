#include "shell.h"

/**
 * _strcpy - this copy a string
 * @dest: destination
 * @src: source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int k = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[k])
	{
		dest[k] = src[k];
		k++;
	}
	dest[k] = 0;
	return (dest);
}

/**
 * _strdup - the duplicate a string
 * @str: string to duplicate
 *
 * Return: the pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int leng = 0;
	char *tre;

	if (str == NULL)
		return (NULL);
	while (*str++)
		leng++;
	tre = malloc(sizeof(char) * (leng + 1));
	if (!tre)
		return (NULL);
	for (leng; leng--;)
		tre[leng] = *--str;
	return (tre);
}

/**
 *_puts - this prints an input string
 *@str: string to be printed
 *
 * Return: 0
 */
void _puts(char *str)
{
	int k = 0;

	if (!str)
		return;
	while (str[k] != '\0')
	{
		_putchar(str[k]);
		k++;
	}
}

/**
 * _putchar - this write the character c to stdout
 * @c: character to print
 *
 * Return: 1 (Success)
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char b)
{
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (b == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(1, buf, k);
		k = 0;
	}
	if (b != BUF_FLUSH)
		buf[k++] = b;
	return (1);
}
