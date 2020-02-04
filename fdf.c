#include "fdf.h"

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
    
    return 0;
}
