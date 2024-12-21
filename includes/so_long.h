//Header Guard
#ifndef SO_LONG_H
# define SO_LONG_H

//Macros
# define MAX_COL 1000000
# define IMG_SIZE 64

//PATHS
# define PLAYER_PATH "./textures/player/down/1.xpm"
# define WALL_PATH "./textures/map/wall.xpm"
# define FLOOR_PATH "./textures/map/floor.xpm"
# define KEY_PATH "./textures/map/key.xpm"
# define DOOR_PATH "./textures/map/door.xpm"
# define FOX_PATH "./textures/map/fox.xpm"
# define UP_IMG	"./textures/player/up.xpm"
# define DOWN_IMG "./textures/player/down.xpm"
# define RIGHT_IMG "./textures/player/right.xpm"
# define LEFT_IMG "./textures/player/left.xpm"

//KEY_CODES
# define ESC_KEY 65307
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100 

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
	int x_spwn;
	int y_spwn;
}w_cord;

typedef struct 
{
	void	*mlx;
	void	*win;
	char	**map;
	w_cord	cord;
	int		collected;
	int		steps;
}w_mlx;

//Prototypes
w_mlx	*ft_mlx_init();
char	**ft_get_map(int fd);
int		ft_input(int keycode, w_mlx *mlx);
void	ft_map_gen(w_mlx *mlx);
void	ft_mlx_print_img(w_mlx *mlx, char *path, int x, int y);
void	ft_exit(w_mlx *mlx);
int		ft_get_coordinates(char **map, int obg, int axis);
int		ft_get_win_size(char **map, int axis);
char	*ft_itoa(int n);
int		ft_key_check(char **map);
void ft_win(w_mlx *mlx);

#endif