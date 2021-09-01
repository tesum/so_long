#ifndef SO_LONG_H
# define SO_LONG_H

# define ERR_MAP	100

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../mlx/mlx.h"
# include "get_next_line.h"

typedef struct s_map
{
	int	C;
	int	E;
	int	P;
	int	width;
	int	height;
}				t_map;


// create map
void	create_map(char *map, t_map *map_s);

// utils
int	err_exit(char *str, int err);

#endif