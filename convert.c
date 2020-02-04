#include "fdf.h"

void three_d(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.523599);
    *y = (*x + *y) * sin(0.523599) - z;
}

void rotate_x(float *y, float *z, int angle)
{
    double radian;
    float temp_y;

    temp_y = *y;
    radian = (double)(angle * 3.14)/(double)180;
    *y = temp_y * cos(radian) + *z * sin(radian);
    *z = -temp_y * sin(radian) + *z * cos(radian);
}

void	rotate_y(float *x, float *z, int angle)
{
    double radian;
    float temp_x;

	temp_x = *x;
    radian = (double)(angle * 3.14)/(double)180;
	*x = temp_x * cos(radian) + *z * sin(radian);
	*z = -temp_x * sin(radian) + *z * cos(radian);
}

void	rotate_z(float *x, float *y, int angle)
{
	float temp_x;
	float temp_y;
    double radian;

	temp_x = *x;
	temp_y = *y;
    radian = (double)(angle * 3.14)/(double)180;
	*x = temp_x * cos(angle) - temp_y * sin(radian);
	*y = temp_y * sin(angle) + temp_y * cos(radian);
}
