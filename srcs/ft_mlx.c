#include "so_long.h"

void *ft_create_win(w_mlx *mlx)
{
	void	*win;
	int		height; 
	int		with;

	height = ft_get_coordinates(mlx->map, 'h', 'y');
	with = ft_get_coordinates(mlx->map, 'w', 'x');
	win = mlx_new_window(mlx->mlx, with * IMG_SIZE, height * IMG_SIZE, "so_long");
	return (win);
}

w_mlx	*ft_mlx_init()
{
	int fd;
	w_mlx *mlx;


	fd = open("maps/map.ber", O_RDWR);
	mlx = malloc(sizeof(w_mlx));

	mlx->mlx = mlx_init();
	mlx->map  = ft_get_map(fd);
	mlx->win = ft_create_win(mlx);
	mlx->cord.x_spwn = ft_get_coordinates(mlx->map, 'P', 'x');
	mlx->cord.y_spwn = ft_get_coordinates(mlx->map, 'P', 'y');
	mlx->collected = 0;

	ft_map_gen(mlx);
	ft_mlx_print_img(mlx, DOWN_IMG, mlx->cord.x_spwn, mlx->cord.y_spwn);
	return (mlx);
}

void ft_mlx_print_img(w_mlx *mlx, char *path, int x, int y)
{
	int 	width;
	int		height;
	void 	*img;
	char 	*steps;

	img = mlx_xpm_file_to_image(mlx->mlx, path, &width, &height);
	if (img == NULL)
 		return;
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, x * IMG_SIZE, y * IMG_SIZE);
	mlx_string_put(mlx->mlx, mlx->win, 5, 12, 0xFF0000, "STEPS : ");
	steps = ft_itoa(mlx->steps);
	mlx_string_put(mlx->mlx, mlx->win, 54, 12, 0xFF0000, steps);
	free(steps);
}
