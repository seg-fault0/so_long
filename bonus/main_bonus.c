/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:27:05 by wimam             #+#    #+#             */
/*   Updated: 2024/12/29 18:39:15 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_start(t_mlx *mlx)
{
	int	size;

	mlx->player = mlx_xpm_file_to_image(mlx->mlx, DOWN_IMG, &size, &size);
	if (!mlx->player)
		return (ft_free_map(mlx->map), close(mlx->fd), free(mlx));
	ft_map_gen(mlx);
	ft_mlx_print_img(mlx, mlx->img->player_down, mlx->px, mlx->py);
}

int	main(int argc, char *argv[])
{
	t_mlx	*mlx;

	if (argc != 2 || ft_check_extension(argv[1]))
		return (-1);
	mlx = ft_mlx_init(argv[1]);
	if (!mlx)
		return (-1);
	ft_start(mlx);
	mlx_key_hook(mlx->win, ft_input, mlx);
	mlx_loop_hook(mlx->mlx, ft_animation, mlx);
	mlx_hook(mlx->win, 17, 0, ft_exit, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
