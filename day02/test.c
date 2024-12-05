#include "main.h"

void ft_print2parray(char **s)
{
    int i;

    i = 0;
    while (*s)
    {
        printf("s%d: %s\n", i, *s);
        i++;
        s++;
    }
    return ;
}

int main(void)
{
    int fd;
    char *b;
    t_node *n;

    printf("TEST atoi():\n");
    printf("expected: 2, actual: %d\n", atoi("02 03 04"));
    printf("\n");

    printf("TEST ft_issafereport():\n");
    n = ft_createnode(strdup("7 6 4 2 1"));
    printf("expected: 1, actual: %d\n", ft_issafereport(n->line));
    n = ft_createnode(strdup("1 2 7 8 9"));
    printf("expected: 0, actual: %d\n", ft_issafereport(n->line));
    n = ft_createnode(strdup("9 7 6 2 1"));
    printf("expected: 0, actual: %d\n", ft_issafereport(n->line));
    n = ft_createnode(strdup("1 3 2 4 5"));
    printf("expected: 0, actual: %d\n", ft_issafereport(n->line));
    n = ft_createnode(strdup("8 6 4 4 1"));
    printf("expected: 0, actual: %d\n", ft_issafereport(n->line));
    n = ft_createnode(strdup("1 3 6 7 9"));
    printf("expected: 1, actual: %d\n", ft_issafereport(n->line));
    n = ft_createnode(strdup("48 50 51 53 54"));
    printf("expected: 1, actual: %d\n", ft_issafereport(n->line));
    n = ft_createnode(strdup("48 50 51 53 56"));
    printf("expected: 0, actual: %d\n", ft_issafereport(n->line));
    printf("\n");

    printf("TEST ft_split():\n");
    printf("expected:\n\t1234\n\t567\n\t89\n");
    printf("actual:\n");
    ft_print2parray(ft_split(strdup("1234\n567\n89"), '\n'));
}
