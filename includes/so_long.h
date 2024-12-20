//Header Guard
#ifndef SO_LONG_H
# define SO_LONG_H

//Macros
# define MAX_COL 1000000

//STD Libraries
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

//NONSTD Libraries
# include "mlx.h"
# include "mlx_int.h"
# include "get_next_line.h"

//Structures
typedef struct 
{
	void	*mlx;
	void	*win;
	void	*player;
	void	*map_img;
}w_mlx;

//Prototypes
char	**get_map(int fd);


#endif