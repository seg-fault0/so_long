#include "so_long.h"

static void ft_mov(w_mlx *mlx, int x, int y, int direction)
{
	ft_map_gen(mlx);
	if (direction == W_KEY)
		ft_mlx_print_img(mlx, UP_IMG, x, y);
	else if (direction == S_KEY)
		ft_mlx_print_img(mlx, DOWN_IMG, x, y);
	else if (direction == A_KEY)
		ft_mlx_print_img(mlx, LEFT_IMG, x, y);
	else if (direction == D_KEY)
		ft_mlx_print_img(mlx, RIGHT_IMG, x, y);
	else
		ft_mlx_print_img(mlx, DOWN_IMG, x, y);
}

static int ft_can_mov(w_mlx *mlx, int x, int y)
{
	int	obg;

	obg = mlx->map[y][x];
	if (obg == '1' || (obg == 'E' && mlx->collected == 0))
		return (0);
	else
	{
		mlx->steps++;
		return (1);
	}
}

int ft_event(w_mlx *mlx, int px, int py)
{
	int current;

	current = mlx->map[py][px];
	if (current == 'C')
		mlx->map[py][px] = '0';
	if (ft_key_check(mlx->map))
		mlx->collected = 1;
	if ((current == 'E' && mlx->collected == 1))
	{
		write(1, "YOU WIN!!", 9);
		ft_exit(mlx);
	}
	if (current == 'B')
	{
		write(1, "YOU LOST!!", 10);
		ft_exit(mlx);
	}
	
}

int ft_input(int keycode, w_mlx *mlx)
{
	static	int	xpo;
	static	int	ypo;

	if(xpo == 0 &&  ypo == 0)
	{
		xpo = mlx->cord.x_spwn;
		ypo = mlx->cord.y_spwn;
	}
	if (keycode == ESC_KEY)
		ft_exit(mlx);
	else if (keycode == W_KEY && ft_can_mov(mlx, xpo, ypo - 1))
		ypo -= 1;
	else if (keycode == S_KEY && ft_can_mov(mlx, xpo, ypo + 1))
		ypo += 1;
	else if (keycode == A_KEY && ft_can_mov(mlx, xpo - 1, ypo))
		xpo -= 1;
	else if (keycode == D_KEY && ft_can_mov(mlx, xpo + 1, ypo))
		xpo += 1;
	ft_mov(mlx, xpo, ypo, keycode);
	ft_event(mlx, xpo, ypo);
}
