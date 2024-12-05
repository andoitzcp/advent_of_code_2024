#ifndef MAIN_H_
#define MAIN_H_

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define BFR_SIZE 100000

typedef struct s_node
{
    char *line;
    struct s_node *next;
} t_node;

// functions
int8_t ft_issafereport(char *s);
char *ft_allocline(char *s);
t_node *ft_createnode(char *s);
void ft_appendnode(t_node **head, t_node *node);
char **ft_split(char *s, char c);
void ft_readinput(int fd, char *bfr);


#endif // MAIN_H_
