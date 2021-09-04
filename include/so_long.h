#ifndef SO_LONG_H
# define SO_LONG_H

# define ERR_ARGS		100
# define ERR_MAP		101
# define ERR_MALLOC		102

# define PATH_PLAYER	"texture/player.xpm"
# define PATH_COIN		"texture/coin.xpm"
# define PATH_DR_C		"texture/door_closed.xpm"
# define PATH_FLOOR		"texture/floor.xpm"
# define PATH_WALL		"texture/wall.xpm"

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "libft.h"

typedef struct s_data
{
	int		x;
	int		y;
	void	*img;
}				t_data;

typedef struct s_map
{
	void	*win;
	void	*mlx;
	int		C;
	int		E;
	int		P;
	int		x;
	int		y;
	int		count;
	int		width;
	int		height;
	t_list	*map_line;
	t_data	*player;
	t_data	*coin;
	t_data	*door;
	t_data	*wall;
	t_data	*floor;
}				t_map;


// create map
void	create_map(char *map, t_map *map_s);
void	print_map(t_map *map);

// utils
int		destroy(void);
int		err_exit(char *str, int err);
int		move(int keycode, t_map *img);

#endif