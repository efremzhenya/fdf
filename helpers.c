#include "fdf.h"

void error(char *msg)
{
    ft_putstr(msg);
    exit(0);
}

void    set_extremums(fdf_struct *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    data->max_z = data->z_matrix[i][j];
    data->min_z = data->z_matrix[i][j];
    while (i < data->h)
    {
        j = 0;
        while (j < data->w)
        {
            if (data->z_matrix[i][j] > data->max_z)
                data->max_z = data->z_matrix[i][j];
            if (data->z_matrix[i][j] < data->min_z)
                data->min_z = data->z_matrix[i][j];
            j++;
        }
        i++;
    }
}

void    set_start_settings(char *arg, fdf_struct *data)
{
        if (!set_size(data, arg))
        {
            free(data);
            error("Invalid map");
        }
        if (!allocate_matrix(data))
        {
            free(data);
            error("Error on malloc");
        }
        if (!read_file(arg, data))
        {
            free(data);
            error("Invalid map");
        }
        set_extremums(data);
        data->s_color = 0x008000;
        data->e_color = 0x800080;
        data->is_isometric = 1;
        data->is_hide = 1;
        data->x_rotate = 0;
        data->y_rotate = 0;
        data->z_rotate = 0;
        data->x_shift = 10;
        data->y_shift = 10;
        data->zoom = 40;

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