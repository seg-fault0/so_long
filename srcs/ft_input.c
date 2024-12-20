#include "so_long.h"

int ft_input(int keycode, w_mlx *mlx)
{	
	if (keycode == ESC_KEY)
		ft_exit(mlx);
	else if (keycode == W_KEY)
		printf("hello \n");
}