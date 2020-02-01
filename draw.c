#include "fdf.h"
#include <math.h>
void three_d(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - z;
} 
void bresenham(float x, float y, float x1, float y1, fdf_struct *data)
{
    float x_step;
    float y_step;
    int max;
    int z;
    int z1;

    z = data->z_matrix[(int)y][(int)x];
    z1 = data->z_matrix[(int)y1][(int)x1];

    x *= data->zoom;
    y *= data->zoom;
    x1 *= data->zoom;
    y1 *= data->zoom;

    three_d(&x, &y, z);
    three_d(&x1, &y1, z1);

    x += 300;
    y += 0;
    x1 += 300; 
    y1 += 0;

    x_step = x1 - x;
    y_step = y1 - y;

    max = MAX(MOD(x_step), MOD(y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, (z > 0 || z1 > 0) ? 0xe80c0c : 0xffffff);
        x += x_step;
        y += y_step;
    }
}

void draw_map(fdf_struct *data)
{
    int x;
    int y;

    y = 0;
    while (data->h > y)
    {
        x = 0;
        while (data->w > x)
        {
            if (x < data->w - 1)
            {
                bresenham (x, y, x + 1, y, data);
            }
            if (y < data->h - 1)
            {
                bresenham (x, y, x, y + 1, data);
            }
            x++;
        }
        y++;
    }
}