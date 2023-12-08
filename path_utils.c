#include "so_long.h"
#include "libraries/ft_printf/ft_printf.h"
#include <stdlib.h>

void   path_f_player(t_path *path)
{
    int i;
    int j;

    i = 0;
    while (path->map[i])
    {
        j = 0;
        while (path->map[i][j])
        {
            if (path->map[i][j] == 'P')
            {
                path->x_index = i;
                path->y_index = j;
            }
            j++;
        }
        i++;
    }
}

void    path_f_collectiable(t_path *path)
{
    int i;
    int j;

    i = 0;
    path->collectibles = 0;
    while (path->map[i])
    {
        j = 0;
        while (path->map[i][j])
        {
            if (path->map[i][j] == 'C')
                path->collectibles++;
            j++;
        }
        i++;
    }
}
void    malloc_error(void)
{
    ft_printf("Error\nMalloc error.\n");
    exit(1);
}