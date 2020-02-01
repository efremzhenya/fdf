#include <stdio.h>
#include "fdf.h"


int key_handler(int key, void *data)
{
    //printf("%i", key);
    return(0);
}

void    print_file(fdf_struct *data)
{
    int i;
    int j;

    i = 0;
    while (i < data->h)
    {
        j = 0;
        while (j < data->w)
        {
            printf("%3d", data->z_matrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

int main(int argc, char **argv)
{
    fdf_struct *data;

    data = (fdf_struct*)malloc(sizeof(fdf_struct));
    if (argc == 2)
    {
        read_file(argv[1], data);
        print_file(data);
        data->zoom = 40;
        data->mlx_ptr = mlx_init();
        data->win_ptr = mlx_new_window(data->mlx_ptr, 2000, 2000, "FDF");
        draw_map(data);
        mlx_key_hook(data->win_ptr, key_handler, NULL);
        mlx_loop(data->mlx_ptr);
    }
    else
    {
        //error
    }
    
    return 0;
}
