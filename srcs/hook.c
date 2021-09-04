#include "so_long.h"

void	print_img(t_map *map, char *file, void *img)
{
	img = mlx_xpm_file_to_image(map->mlx, file, &map->width, &map->height);
	mlx_put_image_to_window(map->mlx, map->win, img, map->x * 40, map->y * 40);

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

void	change_pos(t_map *map, int x, int y)
{
	if (((char *)ch_line(map->map_line, map->y+y)->content)[map->x+x] != '1')
	{
		if (((char *)ch_line(map->map_line, map->y+y)->content)[map->x+x] == 'E' && map->C == 0)
		{
			mlx_destroy_window(map->mlx, map->win);
			printf("U win\n");
			exit(0);
		}
		if (((char *)ch_line(map->map_line, map->y+y)->content)[map->x+x] == 'C')
		{
			map->C -= 1;
			((char *)ch_line(map->map_line, map->y+y)->content)[map->x+x] = '0';
		}
		map->count += 1;
		print_img(map, "texture/floor.xpm", map->floor->img);
		map->x += x;
		map->y += y;
		print_img(map, "texture/player.xpm", map->player->img);
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
		change_pos(img, 0, -1);
	else if (keycode == 0)
		change_pos(img, -1, 0);
	else if (keycode == 1)
		change_pos(img, 0, 1);
	else if (keycode == 2)
		change_pos(img, 1, 0);
	return (0);
}

int	destroy(void)
{
	exit(0);
}