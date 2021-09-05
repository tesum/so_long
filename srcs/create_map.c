#include "so_long.h"

void	check_name(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '.' && map[i])
		i++;
	if (map[i] != '.' || map[i+1] != 'b' || map[i+2] != 'e' || map[i+3] != 'r')
		err_exit("Invalid map name. Need filename.ber", ERR_MAP);
}

void	check_first_and_last_line(char *line, t_map *map, int k)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			err_exit("Invalid map. Incorrect first/last line", ERR_MAP);
		i++;
	}
	if (k == 1)
		map->height += 1;
	map->width = i;
}

void	check_map_line(char *line, t_map *map, char *symbs)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr(symbs, line[i]) == 0)
			err_exit("Invalid map. Incorrect symbol", ERR_MAP);
		if (line[i] == 'P')
			map->P += 1;
		if (line[i] == 'E')
			map->E += 1;
		if (line[i] == 'C')
			map->C += 1;
		if (line[i] == 'V')
			map->V += 1;
		i++;
	}
	if (line[0] != '1' || line[--i] != '1')
		err_exit("Invalid map. Incorrect wall", ERR_MAP);
	i++;
	if (i > map->width || i < map->width)
		err_exit("Invalid map. Incorrect width", ERR_MAP);
	map->width = i;
	map->height += 1;
}

void	init_map(t_map *map_s)
{
	map_s->C = 0;
	map_s->E = 0;
	map_s->P = 0;
	map_s->width = 0;
	map_s->height = 0;
	map_s->img_w = 32;
	map_s->img_h = 32;
}

void	create_map(char *map, t_map *map_s)
{
	int		fd;
	int		k;
	char	*line;

	check_name(map);
	fd = open(map, O_RDONLY);
	if (fd == 0)
		err_exit("Invalid map", ERR_MAP);
	init_map(map_s);
	k = get_next_line(fd, &line);
	check_first_and_last_line(line, map_s, 1);
	while (k > 0)
	{
		ft_lstadd_back(&map_s->map_line, ft_lstnew((void*)line));
		k = get_next_line(fd, &line);
		check_map_line(line, map_s, "01PCEV");
	}
	ft_lstadd_back(&map_s->map_line, ft_lstnew((void*)line));
	check_first_and_last_line(line, map_s, 2);
	if (!map_s->C || !map_s->E || map_s->P != 1)
		err_exit("Invalid map. Haven't Exit/Players/Coin", ERR_MAP);
}