#include "../include/so_long.h"

int	err_exit(char *str, int err)
{
	write(0, "Error\n", 7);
	perror(str);
	exit(err);
}