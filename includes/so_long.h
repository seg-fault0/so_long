//Header Guard
#ifndef SO_LONG_H
# define SO_LONG_H

//Macros
# define MAX_COL 1000000
# define IMG_SIZE 64
# define PLAYER_PATH "./textures/player/down/1.xpm"
# define WALL_PATH "./textures/map/wall.xpm"
# define FLOOR_PATH "./textures/map/floor.xpm"
# define KEY_PATH "./textures/map/key.xpm"

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
}w_mlx;

//Prototypes
char	**ft_get_map(int fd);
void	ft_map_gen(w_mlx *mlx, char **map);
w_mlx	*ft_mlx_init(w_mlx *mlx, int with, int height);
void	ft_mlx_print_img(w_mlx *mlx, char *path, int x, int y);


#endif