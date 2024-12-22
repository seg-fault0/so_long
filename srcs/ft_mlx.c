/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:26:02 by wimam             #+#    #+#             */
/*   Updated: 2024/12/22 16:32:41 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_create_win(t_mlx *mlx)
{
	void	*win;
	int		height;
	int		with;

	height = ft_get_coordinates(mlx->map, 'h', 'y') * IMG_SIZE;
	with = ft_get_coordinates(mlx->map, 'w', 'x') * IMG_SIZE;
	win = mlx_new_window(mlx->mlx, with, height, "so_long");
	return (win);
}

t_mlx	*ft_mlx_init(char *str)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->fd = open(str, O_RDWR);
	if (mlx->fd < 0)
		return (free(mlx), NULL);
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (close(mlx->fd), free(mlx), NULL);
	mlx->map = ft_get_map(mlx->fd);
	if (!mlx->map)
		return (close(mlx->fd), free(mlx), NULL);
	mlx->win = ft_create_win(mlx);
	if (!mlx->win)
		return (ft_free_map(mlx->map), close(mlx->fd), free(mlx), NULL);
	mlx->px = ft_get_coordinates(mlx->map, 'P', 'x');
	mlx->py = ft_get_coordinates(mlx->map, 'P', 'y');
	mlx->keys = ft_key_count(mlx->map);
	mlx->collected = 0;
	ft_map_gen(mlx);
	ft_mlx_print_img(mlx, DOWN_IMG, mlx->px, mlx->py);
	return (mlx);
}

void	ft_mlx_print_img(t_mlx *mlx, char *path, int x, int y)
{
	int		width;
	int		height;
	void	*img;
	char	*steps;

	img = mlx_xpm_file_to_image(mlx->mlx, path, &width, &height);
	if (img == NULL)
		return ;
	x *= IMG_SIZE;
	y *= IMG_SIZE;
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, x, y);
	mlx_string_put(mlx->mlx, mlx->win, 5, 12, 0xFF0000, "STEPS : ");
	steps = ft_itoa(mlx->steps);
	mlx_string_put(mlx->mlx, mlx->win, 54, 12, 0xFF0000, steps);
	free(steps);
}
