/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimamgmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:27:05 by wimam             #+#    #+#             */
/*   Updated: 2024/12/21 18:17:20 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_window(t_mlx *mlx)
{	
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	ft_exit(mlx);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_mlx	*mlx;

	if (argc != 2)
		return (0);
	mlx = ft_mlx_init(argv[1]);
	mlx_key_hook(mlx->win, ft_input, mlx);
	mlx_hook(mlx->win, 17, 0, ft_close_window, mlx);
	mlx_loop(mlx->mlx);
}
