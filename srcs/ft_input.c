#include "so_long.h"

int ft_input(int keycode, w_mlx *mlx)
{
	if(keycode == 119) 		//w
		mlx->player = ft_mov(mlx, 0, -10);
	else if(keycode == 115) //s
		mlx->player = ft_mov(mlx, 0, 10);
	else if(keycode == 97)	//a
		mlx->player = ft_mov(mlx, -10, 0);
	else if(keycode == 100)	//d
		mlx->player = ft_mov(mlx, 10, 0);
	else if(keycode == 65307)//esc
		ft_exit(mlx);
	return (0);
}