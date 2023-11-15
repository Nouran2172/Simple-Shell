#include "shell.h"

int is_chain(info_t *inf, char *bf, size_t *w)
{
	size_t i = *w;

	if (bf[i] == '|' && bf[i + 1] == '|')
	{
		bf[i] = '\0';
		i++;
		inf->cmd_buf_type = CMD_OR;
	}
	else if (bf[i] == '&' && bf[i + 1] == '&')
	{
		bf[i] = '\0';
		i++;
		inf->cmd_buf_type = CMD_AND;
	}
	else if (bf[i] == ';')
	{
		bf[i] = '\0';
		inf->cmd_buf_type = CMD_CHAIN;
	}
	else
	{
        	return 0;
	}
	*w = i;
	return 1;
}
/**
 * check_chain - checks we should continue chaining based on last status
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 * @i: starting position in buf
 * @len: length of buf
 *
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}
int replace_alias(info_t *inf)
{
    int j;
    list_t *node;
    char *w;

    for (j = 0; j < 10; j++)
    {
        node = node_starts_with(inf->alias, inf->argv[0], '=');
        if (!node) return 0;

        free(inf->argv[0]);
        w = _strchr(node->str, '=');
        if (!w) return 0;

        w = _strdup(w + 1);
        if (!w) return 0;

        inf->argv[0] = w;
    }

    return 1;
}

int replace_vars(info_t *inf)
{
    int j = 0;
    list_t *node;

    for (j = 0; inf->argv[j]; j++)
    {
        if (inf->argv[j][0] != '$' || !inf->argv[j][1]) continue;

        if (!_strcmp(inf->argv[j], "$?"))
	{
            replace_string(&(inf->argv[j]), _strdup(convert_number(inf->status, 10, 0)));
            continue;
        }

        if (!_strcmp(inf->argv[j], "$$"))
	{
            replace_string(&(inf->argv[j]), _strdup(convert_number(getpid(), 10, 0)));
            continue;
        }

        node = node_starts_with(inf->env, &inf->argv[j][1], '=');
        if (node)
	{
            replace_string(&(inf->argv[j]), _strdup(_strchr(node->str, '=') + 1));
            continue;
        }

        replace_string(&inf->argv[j], _strdup(""));
    }

    return 0;
}

int replace_string(char **old, char *new)
{
    free(*old);
    *old = new;
    return 1;
}

