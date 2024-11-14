#ifndef SO_LONG_H
# define SO_LONG_H

//libraries
# include "mlx.h"
# include "utils.h"

// structures
typedef struct
{
	void *image;
	int height;
	int width;
	int x_axis;
	int y_axis;
} player_t;

//prototpes
player_t	player_init(void *mlx, void *win, char *img_path);
int			player_mouvement(player_t player, int keycode);

#endif
