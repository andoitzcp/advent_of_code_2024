#include "main.h"

int main(int argc, char **argv)
{
    int fd;
    int i;
    int count;
    char *bfr;
    char **arr;
    t_node *head;
    t_node *p;

    if (argc != 2)
    {
        printf("wrong number of inputs\n");
        return (1);
    }
    bfr = calloc(BFR_SIZE, 1);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("open file failed");
        return (1);
    }
    ft_readinput(fd, bfr);
    close(fd);
    arr = ft_split(bfr, '\n');
    i = 0;
    head = NULL;
    while (arr[i])
    {
        p = ft_createnode(arr[i]);
        /* printf("line: %s\n", p->line); */
        ft_appendnode(&head, p);
        i++;
    }
    p = head;
    count = 0;
    while (p)
    {
        printf("line: %s\n", p->line);
        count += ft_issafereport(p->line);
        printf("count: %d\n", count);
        p = p->next;
    }
    printf("safe reports: %d\n", count);
    return (0);
}
