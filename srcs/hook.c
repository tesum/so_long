#include "so_long.h"

void	print_img(t_map *map, char *file, void *img, char c)
{
	img = mlx_xpm_file_to_image(map->mlx, file, &map->width, &map->height);
	if (c == 'V')
		mlx_put_image_to_window(map->mlx, map->win, img, map->enemy->x * 32, map->enemy->y * 32);
	else
		mlx_put_image_to_window(map->mlx, map->win, img, map->x * 32, map->y * 32);

}

t_list	*ch_line(t_list *head, int y)
{
	int		i;
	t_list *line;

	i = 0;
	line = head;
	while (i++ < y)
		line = line->next;
	return (line);
}

static void	change_pos(t_map *map, int x, int y, int key)
{
	char	*coord;

	coord = ((char *)ch_line(map->map_line, map->y+y)->content);
	if (coord[map->x+x] != '1')
	{
		if (coord[map->x+x] == 'E' && map->C == 0)
			end_game(map, WIN_GAME);
		if (map->x+x == map->enemy->x && map->y+y == map->enemy->y)
			end_game(map, LOST_GAME);
		if (coord[map->x+x] == 'C')
		{
			map->C -= 1;
			coord[map->x+x] = '0';
		}
		map->count += 1;
		if (((char *)ch_line(map->map_line, map->y)->content)[map->x] != 'E')
			print_img(map, PATH_FLOOR, map->floor->img, 'f');
		if (((char *)ch_line(map->map_line, map->y)->content)[map->x] == 'E')
			print_img(map, PATH_DR_CLOSE, map->door->img, 'd');
		map->x += x;
		map->y += y;
		print_player(map, key);
		move_enemy(map);
	}
}

int	move(int keycode, t_map *img)
{
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->win);
		exit(0);
	}
	else if (keycode == 13)
		change_pos(img, 0, -1, 0);
	else if (keycode == 0)
		change_pos(img, -1, 0, 1);
	else if (keycode == 1)
		change_pos(img, 0, 1, 0);
	else if (keycode == 2)
		change_pos(img, 1, 0, 0);
	return (0);
}

int	destroy(void)
{
	exit(0);
}