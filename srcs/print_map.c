#include "so_long.h"

void	data_mem(t_map *map)
{
	map->player = malloc(sizeof(t_data));
	if (!map->player)
		err_exit("Malloc is dead / P", ERR_MALLOC);
	map->coin = malloc(sizeof(t_data));
	if (!map->coin)
		err_exit("Malloc is dead / C", ERR_MALLOC);
	map->door = malloc(sizeof(t_data));
	if (!map->door)
		err_exit("Malloc is dead / D", ERR_MALLOC);
	map->wall = malloc(sizeof(t_data));
	if (!map->wall)
		err_exit("Malloc is dead / W", ERR_MALLOC);
	map->floor = malloc(sizeof(t_data));
	if (!map->floor)
		err_exit("Malloc is dead / F", ERR_MALLOC);
	map->enemy = malloc(sizeof(t_data));
	if (!map->enemy)
		err_exit("Malloc is dead / V", ERR_MALLOC);
}

void	init_img(t_map *map, char *file, void *img, char c)
{
	int		len;
	int		i;
	int		h;
	t_list	*line;

	h = 0;
	line = map->map_line;
	while (line)
	{
		i = 0;
		len = map->width;
		while (len--)
		{
			if (((char *)line->content)[i] == c)
			{
				img = mlx_xpm_file_to_image(map->mlx, file, &map->img_w, &map->img_h);
				if (((char *)line->content)[i] == 'P')
				{
					map->x = i;
					map->y = h;
				}
				mlx_put_image_to_window(map->mlx, map->win, img, i * 32, h * 32);
			}
			i++;
		}
		h++;
		line = line->next;
	}
}

void	print_map(t_map *map)
{
	data_mem(map);
	map->mlx = mlx_init();
	printf("%d %d %d\n", map->width, map->height, map->C);
	map->win = mlx_new_window(map->mlx, map->width * 32, map->height * 32, "so_long");
	init_img(map, PATH_COIN, map->coin->img, 'C');
	init_img(map, PATH_PLAYER, map->player->img, 'P');
	printf("Done\n");
	init_img(map, PATH_ENEMY, map->enemy->img, 'V');
	map->count = 0;
	init_img(map, PATH_DR_CLOSE, map->door->img, 'E');
	init_img(map, PATH_FLOOR, map->floor->img, '0');
	init_img(map, PATH_WALL, map->wall->img, '1');
	mlx_hook(map->win, 2, 1L << 0, move, map);
	mlx_loop_hook(map->mlx, coin, map);
	mlx_hook(map->win, 17, 1L << 0, destroy, map);
	mlx_loop(map->mlx);
}
