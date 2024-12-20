#include "so_long.h"

int ft_input(int keycode, w_mlx *mlx)
{
	static	float	xpo;
	static	float	ypo;
	float	speed;

	speed = 10;
	if (keycode == ESC_KEY)
		ft_exit(mlx);
	else if (keycode == W_KEY)
		ypo -= speed;
	else if (keycode == S_KEY)
		ypo += speed;
	else if (keycode == A_KEY)
		xpo -= speed;
	else if (keycode == D_KEY)
		xpo += speed;
	ft_player_gen(mlx, xpo, ypo);
}
