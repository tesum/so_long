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
		init_img(map, PATH_DR_OPEN, map->door->img, 'E');
	if (map->V > 0)
	{

	}
	return (0);
}

void	print_player(t_map *map, int key)
{
	if (((char *)ch_line(map->map_line, map->y)->content)[map->x] == 'E')
			print_img(map, PATH_PLAYER4, map->player->img);
	else
	{
		if (map->count % 2 != 0)
		{
			if (key)
				print_img(map, PATH_PLAYER3, map->player->img);
			else
				print_img(map, PATH_PLAYER2, map->player->img);
		}
		else
			print_img(map, PATH_PLAYER, map->player->img);
	}
}

void	get_coord(t_map *map, char content, int i, int h)
{
	if (content == 'P')
	{
		map->x = i;
		map->y = h;
	}
	if (content == 'V')
	{
		map->x = i;
		map->y = h;
	}

}