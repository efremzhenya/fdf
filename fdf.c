//#include <stdio.h>
#include "fdf.h"


int key_handler(int key, void *data)
{
    //printf("%i", key);
    return(0);
}

int main(int argc, char **argv)
{
    fdf_struct *data;
    data = (fdf_struct*)malloc(sizeof(fdf_struct));
    if (argc == 2)
    {
        read_file(argv[1], data);
    }
    return 0;
}