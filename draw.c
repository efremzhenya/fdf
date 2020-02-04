#include "fdf.h"

void    bresenham(fdf_point p1, fdf_point p2, fdf_struct *data)
{
    fdf_point step;
    int max;
    float z;
    float z1;
    int color;
    fdf_point current;
    fdf_point start;
    fdf_point end;

    color = (p1.z > 0 || p2.z > 0) ? 1 : 0;
    translation_xyz(&p1, &p2, data);

    step.x = p2.x - p1.x;
    step.y = p2.y - p1.y;
    step.z = p2.z - p1.z;
    max = MAX(MOD(step.x), MOD(step.y));
    step.x /= max;
    step.y /= max;
    step.z /= max;

    if (p1.z > p2.z)
    {
        start.z = p2.z;
        end.z = p1.z;
    }
    else
    {
        start.z = p1.z;
        end.z = p2.z;
    }

    start.color = 0x008000;
    end.color = 0x800080;
    while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
    {
        current.z = p1.z;
        if (color == 1)
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, p1.x, p1.y, get_color(current, start, end));
        else
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, p1.x, p1.y, start.color);
        p1.x += step.x;
        p1.y += step.y;
        p1.z += step.z;
    }
}

void draw_map(int x, int y, fdf_struct *data)
{
    fdf_point p1;
    fdf_point p2;

    before_draw(data);
    while (data->h > y)
    {
        x = 0;
        while (data->w > x)
        {
            p1 = (fdf_point){.x = x, .y = y, .z = data->z_matrix[y][x]};
            if (x < data->w - 1)
            {
                p2 = (fdf_point){.x = x + 1, .y = y, .z = data->z_matrix[y][x + 1]};
                bresenham(p1, p2, data);
            }
            if (y < data->h - 1)
            {
                p2 = (fdf_point){.x = x, .y = y + 1, .z = data->z_matrix[y + 1][x]};
                bresenham(p1, p2, data);
            }
            x++;
        }
        y++;
    }
}

void before_draw(fdf_struct *data)
{
    char *msg;

    if (data->x_rotate >= 360)
        data->x_rotate = 0;
    if (data->x_rotate <= -3)
        data->x_rotate = 357;
    if (data->y_rotate >= 360)
        data->y_rotate = 0;
    if (data->y_rotate <= -3)
        data->y_rotate = 357;
    if (data->z_rotate >= 360)
        data->z_rotate = 0;
    if (data->z_rotate <= -3)
        data->z_rotate = 357;
    if (data->zoom >= 200 || data->zoom <= 0)
    {
        msg = "ERROR ON MAX/MIN ZOOM!";
        mlx_string_put(data->mlx_ptr, data->win_ptr, (WINWIDTH-170)/2, (WINHEIGHT-100)/2, 0xE85E5E, msg);
        data->zoom = (data->zoom>=200) ? 200 : 1;
    }
}

void	draw_menu(fdf_struct *data)
{
	char *msg;
    char *value;
    char *k;
    if (data->is_hide)
    {
        msg = "MOVE: up, down, left, right";
        mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 5, 0xE85E5E, msg);
        msg = "VIEW MODE: space";
        mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 20, 0x03fc35, msg);
        msg = "ZOOM: +, -";
        mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 35, 0x03fc35, msg);
        msg = "ROTATE AXIS X: 2, 8; AXIS Y: 4, 6";
        mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 50, 0x03fc35, msg);
        msg = "EXIT: Esc";
        mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 65, 0x03fc35, msg);
        msg = "HIDE INFO: H";
        mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 80, 0x03fc35, msg);   
    }
}