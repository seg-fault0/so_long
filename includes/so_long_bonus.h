/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:27:59 by wimam             #+#    #+#             */
/*   Updated: 2024/12/29 16:14:17 by wimam            ###   ########.fr       */
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
# define UP_IMG	"./textures/player/up.xpm"
# define DOWN_IMG "./textures/player/down.xpm"
# define RIGHT_IMG "./textures/player/right.xpm"
# define LEFT_IMG "./textures/player/left.xpm"

//BonusPATH
# define F1 "./textures/fox/1.xpm" 
# define F2 "./textures/fox/2.xpm" 
# define F3 "./textures/fox/3.xpm" 
# define F4 "./textures/fox/4.xpm" 
# define F5 "./textures/fox/5.xpm" 

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
# include "get_next_line_bonus.h"

//Structures
typedef struct s_img
{
	void	*player_right;
	void	*player_left;
	void	*player_up;
	void	*player_down;
	void	*floor;
	void	*wall;
	void	*door;
	void	*key;
	void	*fox;
}t_img;

typedef struct s_mlx
{
	int		fd;
	void	*mlx;
	void	*win;
	char	**map;
	t_img	*img;
	int		px;
	int		py;
	int		keys;
	int		collected;
	int		steps;
	void	*player;
}t_mlx;

//Prototypes
t_mlx	*ft_mlx_init(char *str);
char	**ft_get_map(int fd);
int		ft_input(int keycode, t_mlx *mlx);
void	ft_map_gen(t_mlx *mlx);
void	ft_mlx_print_img(t_mlx *mlx, void *img, int x, int y);
int		ft_exit(t_mlx *mlx);
int		ft_get_coordinates(char **map, int obg, int axis);
int		ft_get_win_size(char **map, int axis);
char	*ft_itoa(int n);
int		ft_key_count(char **map);
void	ft_win(t_mlx *mlx);
void	ft_free_map(char **map);
t_img	*ft_get_images(t_mlx *mlx);
char	**ft_ckeck_map(char **map);
int		ft_strlen(char *str);
char	*ft_strdup(char *s);
int		ft_check_extension(char *path);

//bonus
int		ft_animation(t_mlx *mlx);
void	ft_mov(t_mlx *mlx, int direction);
void	ft_get_frames(t_mlx *mlx);

#endif