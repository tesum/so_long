#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc == 2)
	{
		map = malloc(sizeof(t_map));
		create_map(argv[1], map);
		print_map(map);
		free(map);
	}
	else
		err_exit("Invalid args. Insert filename", ERR_ARGS);
	return (0);
}
