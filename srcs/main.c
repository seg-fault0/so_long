#include "so_long.h"

int main(int argc, char *argv[])
{
	char **map;
	w_mlx *mlx;
	int fd = open("maps/map.ber", O_RDWR);

	map = ft_get_map(fd);
	mlx = ft_mlx_init(mlx, 1344, 832);

	ft_map_gen(mlx, map);
	ft_player_gen(mlx, map);

	mlx_hook(mlx->win, 2, 1L<<0, ft_input, mlx);
	mlx_loop(mlx->mlx);
}