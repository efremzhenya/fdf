#include "fdf.h"

void    bresenham(float x, float y, float x1, float y1, fdf_struct *data)
{
    float x_step;
    float y_step;
    float z_step;
    int max;
    float z;
    float z1;
    int color;
    fdf_point current;
    fdf_point start;
    fdf_point end;
    fdf_point delta;
    z = data->z_matrix[(int)y][(int)x];
    z1 = data->z_matrix[(int)y1][(int)x1];

    color = (z > 0 || z1 > 0) ? 0xe80c0c : 0xffffff;
    rotate_x(&y, &z, data->x_rotate);
    rotate_x(&y1,&z1, data->x_rotate);
    rotate_y(&x, &z, data->y_rotate);
    rotate_y(&x1,&z1, data->y_rotate);
    rotate_z(&x, &y, data->z_rotate);
    rotate_z(&x1, &y1, data->z_rotate);
    x *= data->zoom;
    y *= data->zoom;
    z *= data->zoom;
    z1 *= data->zoom;
    x1 *= data->zoom;
    y1 *= data->zoom;

    x += data->x_shift;
    y += data->y_shift;
    x1 += data->x_shift;
    y1 += data->y_shift;

    if (data->is_isometric)
    {
        three_d(&x, &y, z);
        three_d(&x1, &y1, z1);
    }

    x_step = x1 - x;
    y_step = y1 - y;
    z_step = z1 - z;

    max = MAX(MOD(x_step), MOD(y_step));
    x_step /= max;
    y_step /= max;
    z_step /= max;

    if (z > z1)
    {
        start.z = z1;
        end.z = z;
    }
    else
    {
        start.z = z;
        end.z = z1;
    }
    
    delta.z = z_step;

    start.color = 0x008000;
    end.color = 0x800080;
    while ((int)(x - x1) || (int)(y - y1))
    {
        current.z = z;
        if (color == 0xe80c0c)
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, get_color(current, start, end, delta));
        else
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
        x += x_step;
        y += y_step;
        z += z_step;
    }
}

void draw_map(fdf_struct *data)
{
    int x;
    int y;

    before_draw(data);
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


void before_draw(fdf_struct *data)
{
    if (data->x_rotate == 360)
        data->x_rotate = 0;
    if (data->x_rotate == -3)
        data->x_rotate = 357;

    if (data->y_rotate == 360)
        data->y_rotate = 0;
    if (data->y_rotate == -3)
        data->y_rotate = 357;

    if (data->z_rotate == 360)
        data->z_rotate = 0;
    if (data->z_rotate == -3)
        data->z_rotate = 357;
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
        
        //value = (char*)malloc(sizeof(char) * (10 + 1));
        //*(value + 0) = "Rotate X:";
        // variable[0] = 'X';
        // variable[1] = ':';
        // variable[2] = ' ';
        // int size = ft_strlen(ft_itoa(data->x_shift)); 
        // value = ft_memalloc(size + 1);

        // value = ft_itoa(data->x_shift);
        // free(value);
    }
}