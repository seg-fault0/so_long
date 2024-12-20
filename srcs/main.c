#include "so_long.h"

int main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDWR);
	char **map = get_map(fd);
	w_mlx *mlx = malloc(sizeof(w_mlx));
	int size;
	void *img;

	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 336, 208, "so_long");

	for(int i = 0; map[i] != NULL; i++)
	{
		for(int j = 0; map[i][j] != '\n'; j++)
		{
			if(map[i][j] == '1')
			{
				img = mlx_xpm_file_to_image(mlx->mlx, "textures/map/wall.xpm", &size, &size);
				mlx_put_image_to_window(mlx->mlx, mlx->win, img, j * 16, i * 16);
			}
			else if(map[i][j] == '0')
			{
				img = mlx_xpm_file_to_image(mlx->mlx, "textures/map/floor.xpm", &size, &size);
				mlx_put_image_to_window(mlx->mlx, mlx->win, img, j * 16, i * 16);
			}
		}
	}
	mlx_loop(mlx->mlx);
}