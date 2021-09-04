#include "so_long.h"

static void	change_pos(t_map* map, int x, int y)
{
	char	*coord;
	char	*coord_now;

	coord = ((char *)ch_line(map->map_line, map->enemy->y+y)->content);
	coord_now = ((char *)ch_line(map->map_line, map->enemy->y)->content);
	if (coord[map->enemy->x+x] != '1')
	{
		if (coord[map->enemy->x+x] != 'C' || coord[map->enemy->x+x] != 'E')
			print_img(map, PATH_FLOOR, map->floor->img, 'V');
		if (coord_now[map->enemy->x] == 'C')
			print_img(map, PATH_COIN, map->coin->img, 'V');
		map->enemy->x += x;
		map->enemy->y += y;
		if (map->count % 2)
			print_img(map, PATH_ENEMY, map->enemy->img, 'V');
		else
			print_img(map, PATH_ENEMY2, map->enemy->img, 'V');
	}
}

void	move_enemy(t_map *map)
{
	int	direction;

	if (map->V > 0)
	{
		direction = (map->count * 73129 + 95121) % 100 + 3;
		if (direction >= 20 && direction <= 50)
			change_pos(map, 0, 1);
		if (direction > 50 && direction <= 80)
			change_pos(map, 1, 0);
		if (direction >= 0 && direction < 20)
			change_pos(map, 0, -1);
		if (direction > 80 && direction < 150)
			change_pos(map, -1, 0);
		if (map->x == map->enemy->x && map->y == map->enemy->y)
			end_game(map, LOST_GAME);
	}
}