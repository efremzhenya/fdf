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

void     set_size(fdf_struct *data, char *name)
{
    char *line;
    int fd;
    int isWidthReaded;

    isWidthReaded = 0;
    fd = open(name, O_RDONLY, 0);
    while (get_next_line(fd, &line))
    {
        if (!isWidthReaded)
        {
            data->w = ft_wdcounter(line, ' ');
        }
        data->h++;
        free(line);
    }
    close(fd);
}

void fill_matrix(int *new_line, char *line)
{
    int i;
    int j;
    char **z_arr;

    i = 0;
    j = 0;
    z_arr = ft_strsplit(line, ' ');
    while (z_arr[i])
    {
        new_line[i] = ft_atoi(z_arr[i]);
        free(z_arr[i++]);
    }
    free(z_arr);
}

void  read_file(char* name, fdf_struct *data)
{
    int i;
    int fd;
    char *line;

    i = 0;
    fd = 0;
    set_size(data, name);
    data->z_matrix = (int **)malloc(sizeof(int*) * (data->h + 1));
    while (i <= data->h)
    {
        data->z_matrix[i++] = (int *)malloc(sizeof(int) * data->w + 1);
    }
    i = 0;
    fd = open(name, O_RDONLY, 0);
    while (get_next_line(fd, &line))
    {
        fill_matrix(data->z_matrix[i++], line);
        free(line);
    }
    data->z_matrix[i] = NULL;
    close(fd);
}