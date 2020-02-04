#include "fdf.h"

int key_handler(int key, fdf_struct *data)
{
    if (key == ESC)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        free(data->z_matrix);
        free(data);
        exit(0);
    }
    if (key == NUMPAD_UP)
        data->x_rotate -= 3;
    else if (key == NUMPAD_DOWN)
        data->x_rotate += 3;
    if (key == NUMPAD_LEFT)
        data->y_rotate -= 3;
    else if (key == NUMPAD_RIGHT)
        data->y_rotate += 3;
    else if (key == DOWN)
        data->y_shift += 10;
    else if (key == UP)
        data->y_shift -= 10;
    else if (key == LEFT)
        data->x_shift -= 10;
    else if (key == RIGHT)
        data->x_shift += 10;
    else if (key == NUMPAD_PLUS)
        data->zoom += 10;
    else if (key == NUMPAD_MINUS)
        data->zoom -= 10;
    else if (key == SPACE)
        data->is_isometric = data->is_isometric ? 0 : 1;
    else if (key == 4)
        data->is_hide = data->is_hide ? 0 : 1;
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    draw_map(0, 0, data);
    draw_menu(data);
    
    return(0);
}


int mouse_handler(int key, fdf_struct *data)
{
    if (key == 5) //scroll up
    {
        data->zoom += 5;
    }
    if (key == 4) //scroll down
    {
        data->zoom -= 5;
    }
     draw_map(0, 0, data);
    
    return(0);
}