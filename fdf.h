#ifndef FDF_H
# define FDF_H
# define MAX(a, b) (a > b ? a : b)
# define MOD(a) ((a < 0) ? -a : a)
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"


typedef struct 
{
    int w;
    int h;
    int **z_matrix;
    int zoom;

    void *mlx_ptr;
    void *win_ptr;
}       fdf_struct;

void    read_file(char* name, fdf_struct *data);
int		ft_wdcounter(char const *str, char c);
void    fill_z_matrix(int *new_line, char *line);
void    bresenham(float x, float y, float x1, float y1, fdf_struct *data);
void    draw_map(fdf_struct *data);
void    three_d(float *x, float *y, int z);

#endif