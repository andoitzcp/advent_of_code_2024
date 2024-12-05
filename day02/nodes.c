#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        if (*p != *s + step && *p != *s + 2 * step && *p != *s + 3 * step)
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
    if (!node)
    {
        perror("ft_createnode:");
        exit(EXIT_FAILURE);
    }
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

void ft_appendnode(t_node **head, t_node *node)
{
    t_node *p;

    p = *head;
    if (!p)
    {
        *head = node;
        return ;
    }
    while (p->next)
        p = p->next;
    p->next = node;
    return ;
}

char **ft_split(char *s, char c)
{
    int i;
    int lc;
    int sz;
    char **arr;
    int tmp[BFR_SIZE / 2] = {0};

    i = 0;
    lc = 0;
    sz = strlen(s);
    while (i < sz)
    {
        while (s[i] == c && i < sz)
        {
            s[i] = '\0';
            i++;
        }
        if (s[i] != c && i < sz)
        {
            tmp[lc] = i;
            lc++;
        }
        while (s[i] != c && i < sz)
            i++;
    }
    arr = (char **)calloc(lc + 1, sizeof(char *));
    i = 0;
    while (i < lc)
    {
        arr[i] = strdup(s + tmp[i]);
        i++;
    }
    return (arr);
}

void ft_readinput(int fd, char *bfr)
{
    ssize_t readsz;

    if ((readsz = read(fd, bfr, BFR_SIZE)) == -1)
    {
        perror("ft_readinput");
        exit(EXIT_FAILURE);
    }
    return ;
}
