#include "so_long.h"

void *ft_player(w_mlx *mlx, int x, int y)
{
	static	int	xpo;
	static	int ypo;
	void		*player;
	int			size;
	
	if(mlx->player != NULL)
		mlx_destroy_image(mlx->mlx, mlx->player);

	xpo += x;
	ypo += y;
	size = 20;

	player = mlx_xpm_file_to_image(mlx->mlx, "assets/player.xpm", &size, &size);
	
	mlx_put_image_to_window(mlx->mlx, mlx->win, player, xpo, ypo);

	return(player);
}