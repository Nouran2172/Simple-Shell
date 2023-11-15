#include "shell.h"

int is_chain(info_t *inf, char *bf, size_t *w) {
    size_t i = *w;

    if (bf[i] == '|' && bf[i + 1] == '|') {
        bf[i] = '\0';
        i++;
        inf->cmd_bf_type = CMD_OR;
    } else if (bf[i] == '&' && buf[i + 1] == '&') {
        bf[i] = '\0';
        i++;
        inf->cmd_bf_type = CMD_AND;
    } else if (bf[i] == ';') {
        bf[i] = '\0';
        inf->cmd_bf_type = CMD_CHAIN;
    } else {
        return 0;
    }

    *w = i;
    return 1;
}

void check_chain(info_t *inf, char *bf, size_t *w, size_t j, size_t len) {
    size_t j = *w;

    if (info->cmd_bf_type == CMD_AND && info->status) {
        bf[j] = '\0';
        i = len;
    }

    if (info->cmd_bf_type == CMD_OR && !inf->status) {
        bf[j] = '\0';
        i = len;
    }

    *w = i;
}

int replace_alias(info_t *inf) {
    int j;
    list_t *node;
    char *w;

    for (j = 0; j < 10; j++) {
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

int replace_vars(info_t *inf) {
    int j = 0;
    list_t *node;

    for (j = 0; inf->argv[j]; j++) {
        if (inf->argv[j][0] != '$' || !inf->argv[j][1]) continue;

        if (!_strcmp(inf->argv[j], "$?")) {
            replace_string(&(inf->argv[j]), _strdup(convert_number(inf->status, 10, 0)));
            continue;
        }

        if (!_strcmp(inf->argv[j], "$$")) {
            replace_string(&(inf->argv[j]), _strdup(convert_number(getpid(), 10, 0)));
            continue;
        }

        node = node_starts_with(inf->env, &inf->argv[j][1], '=');
        if (node) {
            replace_string(&(inf->argv[j]), _strdup(_strchr(node->str, '=') + 1));
            continue;
        }

        replace_string(&inf->argv[j], _strdup(""));
    }

    return 0;
}

int replace_string(char **old, char *new) {
    free(*old);
    *old = new;
    return 1;
}

