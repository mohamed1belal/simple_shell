#include "shell.h"

/**
  * _eputs - Print a string to stderr
  * @str: The string to be printed
  */
void _eputs(char *str)
{
	if (str)
	{
		while (*str)
		{
			_eputchar(*str);
			str++;
		}
	}
}

/**
  * _eputchar - Write a character to stderr
  * @c: The character to print
  *
  * Return: On success, return 1.
  * On error, return -1 and set errno appropriately.
  */
int _eputchar(char c)
{
	static char buf[WRITE_BUF_SIZE];
	static int i;

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}

	if (c != BUF_FLUSH)
	{
		buf[i] = c;
		i++;
	}

	return (1);
}

/**
  * _putfd - Write a character to the given file descriptor
  * @c: The character to print
  * @fd: The file descriptor to write to
  *
  * Return: On success, return 1.
  * On error, return -1 and set errno appropriately.
  */
int _putfd(char c, int fd)
{
	static char buf[WRITE_BUF_SIZE];
	static int i;

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}

	if (c != BUF_FLUSH)
	{
		buf[i] = c;
		i++;
	}

	return (1);
}

/**
  * _putsfd - Write a string to the given file descriptor
  * @str: The string to be printed
  * @fd: The file descriptor to write to
  *
  * Return: The number of characters written
  */
int _putsfd(char *str, int fd)
{
	int count = 0;

	if (str)
	{
		while (*str)
		{
			count += _putfd(*str, fd);
			str++;
		}
	}

	return (count);
}
