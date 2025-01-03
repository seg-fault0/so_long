/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:27:05 by wimam             #+#    #+#             */
/*   Updated: 2025/01/03 15:35:15 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_start(t_mlx *mlx)
{
	mlx->player = mlx->img->player_down;
	if (!mlx->player)
		ft_exit(mlx);
	ft_map_gen(mlx);
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
