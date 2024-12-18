#include "so_long.h"

void *ft_mov(w_mlx *mlx, int x, int y)
{
	static	int	xpo;
	static	int ypo;
	void		*player;
	int			size;
	
	if(mlx->player != NULL)
		mlx_destroy_image(mlx->mlx, mlx->player);

	xpo += x;
	ypo += y;
	player = mlx_print_image(mlx, "assets/player.xpm", xpo, ypo);

	return(player);
}