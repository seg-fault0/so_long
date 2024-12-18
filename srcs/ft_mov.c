#include "so_long.h"

void *ft_mov(w_mlx *mlx, int x, int y)
{
	static	int	xpo;
	static	int ypo;
	void		*player;

	xpo += x;
	ypo += y;
	player = mlx_print_image(mlx, "assets/player.xpm", xpo, ypo, mlx->player);

	return(player);
}