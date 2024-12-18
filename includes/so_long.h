//Header Guard
#ifndef SO_LONG_H
# define SO_LONG_H

//Macros
# define PLAYER_SIZE 10

//STD Libraries
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

//NONSTD Libraries
# include "mlx.h"

//Structures
typedef struct 
{
	void	*mlx;
	void	*win;
	void	*player;
}w_mlx;

//Prototypes
void	*ft_player(w_mlx *mlx, int x, int y);
int		ft_input(int keycode, w_mlx *mlx);
void	ft_exit(w_mlx *mlx);


#endif