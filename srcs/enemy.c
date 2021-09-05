#include "so_long.h"

static void	change_pos(t_map *map, int x, int y, t_data *enemy)
{
	char	*coord;
	char	*coord_now;

	coord = ((char *)ch_line(map->map_line, enemy->y + y)->content);
	coord_now = ((char *)ch_line(map->map_line, enemy->y)->content);
	if (coord[enemy->x + x] != '1')
	{
		if (coord[enemy->x + x] != 'C' || coord[enemy->x + x] != 'E')
			print_img(map, PATH_FLOOR, enemy, 'V');
		if (coord_now[enemy->x] == 'C')
			print_img(map, PATH_COIN, enemy, 'V');
		enemy->x += x;
		enemy->y += y;
		if (map->count % 2)
			print_img(map, PATH_ENEMY, enemy, 'V');
		else
			print_img(map, PATH_ENEMY2, enemy, 'V');
	}
}

void	check_death(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->V)
	{
		if (map->x == map->enemy[i].x && map->y == map->enemy[i].y)
			end_game(map, LOST_GAME);
		i++;
	}
}

void	move_enemy(t_map *map)
{
	int	direction;
	int	i;

	i = 0;
	if (map->V > 0)
	{
		direction = (map->count * 73129 + 95121) % 100 + 3;
		while (i < map->V)
		{
			if (direction >= 20 && direction <= 50)
				change_pos(map, 0, 1, &map->enemy[i]);
			if (direction > 50 && direction <= 80)
				change_pos(map, 1, 0, &map->enemy[i]);
			if (direction >= 0 && direction < 20)
				change_pos(map, 0, -1, &map->enemy[i]);
			if (direction > 80 && direction < 150)
				change_pos(map, -1, 0, &map->enemy[i]);
			check_death(map);
			i++;
		}
	}
}

int	check_enemy(t_list *line, int i)
{
	if (((char *)line->content)[i] == 'V')
	{
		((char *)line->content)[i] = '0';
		return (1);
	}
	return (0);
}
