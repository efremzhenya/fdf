#include "fdf.h"

void    free_arr(fdf_struct *data)
{
    int i;
    int j;

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
    fdf_struct *data;
    data = (fdf_struct*)malloc(sizeof(fdf_struct));
    if (argc == 2)
    {
        set_start_settings(argv[1], data);
        draw_map(0, 0, data);
        draw_menu(data);
        mlx_key_hook(data->win_ptr, key_handler, data);
        mlx_loop(data->mlx_ptr);
    }
    else
    {
        error("Some error\n");
    }
    free_arr(data);
    free(data);
    return 0;
}
