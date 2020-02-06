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
static int		exit_x(void)
{
	exit(1);
	return (0);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        fdf_struct *data;
        if (!(data = (fdf_struct*)malloc(sizeof(fdf_struct))))
            error("Error on malloc");
        data->mlx_ptr = mlx_init();
        data->win_ptr = mlx_new_window(data->mlx_ptr, WINWIDTH, WINWIDTH, "FDF");
        set_start_settings(argv[1], data);
        draw_map(0, 0, data);
        mlx_key_hook(data->win_ptr, key_handler, data);
        mlx_hook(data->win_ptr, 17, 1L << 17, exit_x, NULL);
        mlx_loop(data->mlx_ptr);
        free_arr(data);
        free(data);
        return(0);
    }
    error("No input file\n");
    return (0);
}
