#include "fdf.h"

int		ft_wdcounter(char const *str, char c)
{
	int i;
	int words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

int     set_size(fdf_struct *data, char *name)
{
    char *line;
    int fd;
    int isWidthReaded;

    isWidthReaded = 0;
    data->h =0;
    if ((fd = open(name, O_RDONLY, 0)) < 0)
        return (0);
    while (get_next_line(fd, &line))
    {
        if (!isWidthReaded)
        {
            data->w = ft_wdcounter(line, ' ');
            isWidthReaded = 1;
        }
        if (ft_wdcounter(line, ' ') != data->w)
        {
            free(line);
            close(fd);
            return(0);
        }
        data->h++;
        free(line);
    }
    close(fd);
    return (1);
}

int    fill_matrix(int *new_line, char *line)
{
    int i;
    int error;
    char **z_arr;

    i = 0;
    error = 1;
    z_arr = ft_strsplit(line, ' ');
    while (z_arr[i])
    {
        if (ft_isnumber(z_arr[i], 10))
            new_line[i] = ft_atoi(z_arr[i]);
        else
            error = 0;
        free(z_arr[i++]);
    }
    free(z_arr);
    return error;
}

int     read_file(char* name, fdf_struct *data)
{
    int i;
    int fd;
    char *line;

    i = 0;
    if ((fd = open(name, O_RDONLY, 0)) < 0)
        return (0);
    while (get_next_line(fd, &line))
    {
        if (!fill_matrix(data->z_matrix[i++], line))
        {
            free_arr(data);
            free(line);
            close(fd);
            return (0);
        }
        free(line);
    }
    data->z_matrix[i] = NULL;
    close(fd);
    return (1);
}

int     allocate_matrix(fdf_struct *data)
{
    int i;

    i = 0;
    if (!(data->z_matrix = (int **)malloc(sizeof(int*) * (data->h + 1))))
        return (0);
    while (i <= data->h)
    {
        if (!(data->z_matrix[i++] = (int *)malloc(sizeof(int) * data->w + 1)))
        {
            free_arr(data);
            return (0);
        }
    }
    return (1);
}