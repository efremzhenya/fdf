#include "fdf.h"

void    free_arr(fdf_struct *data)
{
    int i;

    i = 0;
    while (i < data->h)
    {
        free(data->z_matrix[i]);
        i++;
    }
    free(data->z_matrix);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        fdf_struct *data;
        if (!(data = (fdf_struct*)malloc(sizeof(fdf_struct))))
        {
            error("Memory not malloced");
            return (0);
        }
        set_start_settings(argv[1], data);
        draw_map(0, 0, data);
        draw_menu(data);
        mlx_key_hook(data->win_ptr, key_handler, data);
        mlx_loop(data->mlx_ptr);
        free_arr(data);
        free(data);
        return(0);
    }
    else
    {
        error("Some error\n");
    }
    //free_arr(data);
    //free(data);
    return (0);
}
