/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:27:59 by wimam             #+#    #+#             */
/*   Updated: 2024/12/22 10:49:36 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Header Guard
#ifndef SO_LONG_H
# define SO_LONG_H

//Macros
# define MAX_COL 100
# define IMG_SIZE 64

//PATHS
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
# include <fcntl.h>

//NONSTD Libraries
# include "mlx.h"
# include "get_next_line.h"

//Structures
typedef struct s_mlx
{
	int		fd;
	void	*mlx;
	void	*win;
	char	**map;
	int		px;
	int		py;
	int		keys;
	int		collected;
	int		steps;
}t_mlx;

//Prototypes
t_mlx	*ft_mlx_init(char *str);
char	**ft_get_map(int fd);
int		ft_input(int keycode, t_mlx *mlx);
void	ft_map_gen(t_mlx *mlx);
void	ft_mlx_print_img(t_mlx *mlx, char *path, int x, int y);
void	ft_exit(t_mlx *mlx);
int		ft_get_coordinates(char **map, int obg, int axis);
int		ft_get_win_size(char **map, int axis);
char	*ft_itoa(int n);
int		ft_key_count(char **map);
void	ft_win(t_mlx *mlx);
void	ft_free_map(char **map);
int		ft_close_window(t_mlx *mlx);

#endif