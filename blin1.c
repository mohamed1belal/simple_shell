#include "shell.h"

/**
 * myhistory - displays the history list, one command per line, preceded
 *             with line numbers, starting at 0.
 * @info: Structure containing potential arguments.
 * Description: task number 0
 * Return: Always 0
 */

int myhistory(info_t *info)
{
	list_t *node = info->history;
	int line_number = 0;

	while (node)
	{
		_putchar(' ');
		_putchar(' ');
		_putchar(' ');
		_putchar(line_number / 100 + '0');
		_putchar((line_number / 10) % 10 + '0');
		_putchar(line_number % 10 + '0');
		_putchar(' ');
		_puts(node->str);
		node = node->next;
		line_number++;
	}

	return (0);
}

/**
 * unset_alias - unsets an alias by removing it from the alias list.
 * @info: Structure containing potential args
 * @str: The alias string to unset.
 * Description: task number 0
 * Return: 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *p = _strchr(str, '=');

	if (!p)
		return (1);

	*p = '\0';
	delete_node_at_index(&(info->alias), get_node_index(info->alias,
				node_starts_with(info->alias, str, -1)));
	*p = '=';

	return (0);
}

/**
 * set_alias - sets an alias to a string by adding it to the alias list.
 * @info: Structure containing potential arguments.
 * @str: The alias string to set.
 * Description: task number 0
 * Return: 0 on success, 1 on error
 */

int set_alias(info_t *info, char *str)
{
	char *p = _strchr(str, '=');

	if (!p)
		return (1);

	*p = '\0';
	unset_alias(info, str);
	*p = '=';

	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string.
 * @node: The alias node to print.
 * Description: task number 0
 * Return: 0 on success, 1 on error
 */

int print_alias(list_t *node)
{
	char *p = _strchr(node->str, '=');

	if (node && p)
	{
		_puts(" ");
		_puts("'");
		_puts(node->str);
		_puts("'");
		_putchar('\n');
		return (0);
	}

	return (1);
}

/**
 * myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments.
 * Description: task number 0
 * Return: Always 0
 */

int myalias(info_t *info)
{
	int i;
	char *p;
	list_t *node;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}

	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
