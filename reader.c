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

int     get_height(char *name)
{
    char *line;
    int h;
    int fd;

    h = 0;
    fd = open(name, O_RDONLY, 0);
    while (get_next_line(fd, &line))
    {
        h++;
        free(line);
    }
    close(fd);
    return h;
}

int     get_width(char *name)
{
    char *line;
    int w;
    int fd;

    w = 0;
    fd = open(name, O_RDONLY, 0);
    if (get_next_line(fd, &line))
    {
        w = ft_wdcounter(line, ' ');
    }
    else
        return 0;
    
    free(line);
    close(fd);
    return w;
}

void read_file(char* name, fdf_struct *data)
{
    data->h = get_height(name);
    data->w = get_width(name);
}