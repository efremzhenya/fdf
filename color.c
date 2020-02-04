#include "fdf.h"

double percent(int start, int end, int current)
{
    double placement;
    double distance;

    placement = current - start;
    distance = end - start;
    return ((distance == 0) ? 1.0 : (placement / distance));
}

int get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

int get_color(fdf_point current, fdf_point start, fdf_point end)
{
    int     red;
    int     green;
    int     blue;
    double  percentage;

    if (current.color == end.color)
        return (current.color);
        
    percentage = percent(start.z, end.z, current.z);
    red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
    green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
    blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}

int     get_color_z(float current, float start, float end, fdf_struct *data)
{
    int     red;
    int     green;
    int     blue;
    double  percentage;

    if (data->s_color == data->e_color)
        return (data->s_color);
    percentage = percent(start, end, current);
    red = get_light((data->s_color >> 16) & 0xFF, (data->e_color >> 16) & 0xFF, percentage);
    green = get_light((data->s_color >> 8) & 0xFF, (data->e_color >> 8) & 0xFF, percentage);
    blue = get_light(data->s_color & 0xFF, data->e_color & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}