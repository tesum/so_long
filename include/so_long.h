#ifndef SO_LONG_H
# define SO_LONG_H

# define ERR_ARGS		100
# define ERR_MAP		101
# define ERR_MALLOC		102
# define WIN_GAME		"\033[0;32mYou are win!"
# define LOST_GAME		"\033[0;31mYou lost loser"

# define PATH_PLAYER	"texture/player1.xpm"
# define PATH_PLAYER2	"texture/player2.xpm"
# define PATH_PLAYER3	"texture/player3.xpm"
# define PATH_PLAYER4	"texture/player4.xpm"
# define PATH_ENEMY		"texture/enemy1.xpm"
# define PATH_ENEMY2	"texture/enemy2.xpm"
# define PATH_COIN		"texture/coin.xpm"
# define PATH_DR_CLOSE	"texture/door_closed.xpm"
# define PATH_DR_OPEN	"texture/door_open.xpm"
# define PATH_FLOOR		"texture/floor.xpm"
# define PATH_WALL		"texture/wall.xpm"

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "mlx.h"
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
	int		V;
	int		x;
	int		y;
	int		count;
	int		width;
	int		height;
	int		img_w;
	int		img_h;
	t_list	*map_line;
	t_data	*player;
	t_data	*enemy;
	t_data	*coin;
	t_data	*door;
	t_data	*wall;
	t_data	*floor;
}				t_map;


// create map
void	create_map(char *map, t_map *map_s);
void	print_map(t_map *map);
void	init_img(t_map *map, char *file, t_data *img, char c);

// utils
void	move_enemy(t_map *map);
void	print_player(t_map *map, int key);
void	end_game(t_map *map, char *message);
void	print_img(t_map *map, char *file, void *img, char c);
int		destroy(void);
int		coin(t_map *map);
int		err_exit(char *str, int err);
int		move(int keycode, t_map *img);
t_list	*ch_line(t_list *head, int y);



#endif