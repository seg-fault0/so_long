#include "so_long.h"

void	ft_player_gen(w_mlx *mlx, int x, int y)
{
	ft_map_gen(mlx);
	ft_mlx_print_img(mlx, PLAYER_PATH, x, y);
}