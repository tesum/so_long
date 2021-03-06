#include "so_long.h"

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
		print_img(map, PATH_PLAYER4, map->player, 'p');
	else
	{
		if (map->count % 2 != 0)
		{
			if (key)
				print_img(map, PATH_PLAYER3, map->player, 'p');
			else
				print_img(map, PATH_PLAYER2, map->player, 'p');
		}
		else
			print_img(map, PATH_PLAYER, map->player, 'p');
	}
}

void	end_game(t_map *map, char *message)
{
	mlx_destroy_window(map->mlx, map->win);
	printf("%s\nStep count: %d\n", message, map->count);
	exit(0);
}

void	put_count(t_map *map)
{
	int		i;
	int		j;
	char	*c;

	c = ft_strjoin("Step count: ", ft_itoa(map->count));
	if (map->C)
		c = ft_strjoin(ft_strjoin(c, " Coin: "), ft_itoa(map->C));
	else if (map->V)
		c = ft_strjoin(c, " The door is open. Survive");
	else
		c = ft_strjoin(c, " The door is open.");
	i = 0;
	while (i < 32)
	{
		j = 0;
		while (j < 500)
		{
			mlx_pixel_put(map->mlx, map->win, j, i, 00000);
			j++;
		}
		i++;
	}
	mlx_string_put(map->mlx, map->win, 18, 18, 16777215, c);
}
