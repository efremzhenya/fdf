#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

typedef struct 
{
    int w;
    int h;
    int **z_matrix;

    void *mlx_ptr;
    void *win_ptr;
}       fdf_struct;

void read_file(char* name, fdf_struct *data);
int     get_width(char *name);
int     get_height(char *name);
int		ft_wdcounter(char const *str, char c);

#endif