#include "so_long.h"

static void ft_mov(w_mlx *mlx, int x, int y, int direction)
{
	int static reset;
	if (reset < 10)
		reset++;
	else
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		reset = 0;
	}
	ft_map_gen(mlx);
	if (direction == W_KEY)
		ft_mlx_print_img(mlx, UP_IMG, x, y);
	else if (direction == S_KEY)
		ft_mlx_print_img(mlx, DOWN_IMG, x, y);
	else if (direction == A_KEY)
		ft_mlx_print_img(mlx, LEFT_IMG, x, y);
	else if (direction == D_KEY)
		ft_mlx_print_img(mlx, RIGHT_IMG, x, y);
}

int ft_input(int keycode, w_mlx *mlx)
{
	static	float	xpo;
	static	float	ypo;
	float	speed;

	speed = 64;
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
	ft_mov(mlx, xpo, ypo, keycode);
}
