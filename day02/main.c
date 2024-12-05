#include "main.h"

int8_t ft_issafereport(char *s)
{
    char step;
    char *p;

    step = 1;
    if (*s > *(s + 1))
        step *= -1;
    p = s + 1;
    while (*p != '\0')
    {
        if (*p != *s + step && *p != *s + 2 * step)
            return (0);
        s++;
        p++;
    }
    return (1);
}

char *ft_allocline(char *s)
{
    int i;
    char *line;

    i = 0;
    while (*s != '\0')
    {
        while (*s == ' ')
            s++;
        if (*s != ' ' && *s != '\0')
            i++;
        while (*s != ' ' && *s != '\0')
            s++;
    }
    line = calloc(i + 1, sizeof(char));
    if (!line)
    {
        perror("malloc:");
        exit(EXIT_FAILURE);
    }
    return (line);
}

t_node *ft_createnode(char *s)
{
    t_node *node;
    int i;

    node = malloc(sizeof(t_node));
    node->line = ft_allocline(s);
    node->next = NULL;
    i = 0;
    while (*s != '\0')
    {
        while (*s == ' ')
            s++;
        node->line[i] = (char)atoi(s);
        while (*s != ' ' && *s != '\0')
            s++;
        i++;
    }
    return (node);
}
