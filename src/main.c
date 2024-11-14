#include "so_long.h"


int	main(void)
{
	//variable
	void		*mlx;
	void		*win;
	player_t	player;

	// mlx && win init
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1200, 900, "GAME");
	
	//make a player
	player = player_init(mlx, win, "./assets/images/player.xpm");
	

	// loop
	mlx_loop(mlx);

	return (0);
}

