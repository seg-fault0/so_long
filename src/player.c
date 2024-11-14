#include "so_long.h"

player_t player_init(void *mlx, void *win, char *img_path)
{
	player_t player;

	// Initialize player dimensions
	player.height = 10;
	player.width = 10;
	player.x_axis = 600;
	player.y_axis = 450;

	// Load the image
	player.image = mlx_xpm_file_to_image(mlx, img_path, &player.width, &player.height);
	if (!player.image)
		return player;

	mlx_put_image_to_window(mlx, win, player.image, player.x_axis, player.y_axis);

	return player;
}