#include "so_long.h"

int main(int argc, char *argv[])
{
	char **map;
	w_mlx *mlx;
	int fd = open("maps/map.ber", O_RDWR);

	map = ft_get_map(fd);
	mlx = ft_mlx_init(mlx, 1344, 832);

	ft_map_gen(mlx, map);
	mlx_loop(mlx->mlx);
}