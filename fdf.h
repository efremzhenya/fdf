#ifndef FDF_H
# define FDF_H
# define MAX(a, b) (a > b ? a : b)
# define MOD(a) ((a < 0) ? -a : a)
# define WINWIDTH 1000
# define WINHEIGHT 1000
# define ESC 53
# define RIGHT 124
# define LEFT 123
# define DOWN 125
# define UP 126
# define NUMPAD_UP 91 
# define NUMPAD_DOWN 84
# define NUMPAD_LEFT 86 
# define NUMPAD_RIGHT 88
# define NUMPAD_PLUS 69 
# define NUMPAD_MINUS 78
# define SPACE 49
# include <math.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

typedef struct 
{
    int w;
    int h;
    int **z_matrix;
    int zoom;
    int x_shift;
    int y_shift;
    int x_rotate;
    int y_rotate;
    int z_rotate;
    int is_isometric;
    int is_hide;
    int s_color;
    int e_color;
    int max_z;
    int min_z;
    void *mlx_ptr;
    void *win_ptr;
}       fdf_struct;

typedef struct 
{
    float x;
    float y;
    float z;
    int color;
}       fdf_point;

void    read_file(char* name, fdf_struct *data);
int		ft_wdcounter(char const *str, char c);
void    fill_z_matrix(int *new_line, char *line);
void    bresenham(fdf_point p1, fdf_point p2, fdf_struct *data);
void    draw_map(int x, int y, fdf_struct *data);
void    three_d(float *x, float *y, int z);
int     key_handler(int key, fdf_struct *data);
void	draw_menu(fdf_struct *data);
void    rotate_x(float *y, float *z, int angle);
void	rotate_y(float *x, float *z, int angle);
void	rotate_z(float *x, float *y, int angle);
void    before_draw(fdf_struct *data);
void    error(char *msg);
int     get_color(fdf_point current, fdf_point start, fdf_point end);
void    set_start_settings(char *arg,fdf_struct *data);
void    translation_xyz(fdf_point *p1, fdf_point *p2, fdf_struct *data);
void    set_extremums(fdf_struct *data);
int     get_color_z(float current, float start, float end, fdf_struct *data);

#endif