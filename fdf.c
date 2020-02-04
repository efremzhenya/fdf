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
    draw_map(data);
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
     draw_map(data);
    
    return(0);
}

// void    print_file(fdf_struct *data)
// {
//     int i;
//     int j;

//     i = 0;
//     while (i < data->h)
//     {
//         j = 0;
//         while (j < data->w)
//         {
//             printf("%3d", data->z_matrix[i][j]);
//             j++;
//         }
//         printf("\n");
//         i++;
//     }
// }

int main(int argc, char **argv)
{
    fdf_struct *data;

    data = (fdf_struct*)malloc(sizeof(fdf_struct));
    if (argc == 2)
    {
        read_file(argv[1], data);
        data->is_isometric = 1;
        data->is_hide = 1;
        data->x_rotate = 0;
        data->y_rotate = 0;
        data->z_rotate = 0;
        data->x_shift = 10;
        data->y_shift = 10;
        
        //print_file(data);
        data->zoom = 40;
        data->mlx_ptr = mlx_init();
        data->win_ptr = mlx_new_window(data->mlx_ptr, WINWIDTH, WINWIDTH, "FDF");
        draw_map(data);
        draw_menu(data);
        mlx_key_hook(data->win_ptr, key_handler, data);
        mlx_loop(data->mlx_ptr);
    }
    else
    {
        error("Some error\n");
    }
    
    return 0;
}
