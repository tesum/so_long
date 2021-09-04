#include "../include/so_long.h"

int	err_exit(char *str, int err)
{
	write(0, "Error\n", 7);
	perror(str);
	exit(err);
}

int	coin(t_map *map)
{
	if (map->C == 0)
		init_img(map, PATH_DR_OPEN, map->door, 'E');
	return (0);
}

void	print_player(t_map *map, int key)
{
	if (((char *)ch_line(map->map_line, map->y)->content)[map->x] == 'E')
			print_img(map, PATH_PLAYER4, map->player->img, 'p');
	else
	{
		if (map->count % 2 != 0)
		{
			if (key)
				print_img(map, PATH_PLAYER3, map->player->img, 'p');
			else
				print_img(map, PATH_PLAYER2, map->player->img, 'p');
		}
		else
			print_img(map, PATH_PLAYER, map->player->img, 'p');
	}
}

void	end_game(t_map *map, char *message)
{
	mlx_destroy_window(map->mlx, map->win);
	printf("%s\n", message);
	exit(0);
}
