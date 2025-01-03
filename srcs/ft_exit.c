/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:24:22 by wimam             #+#    #+#             */
/*   Updated: 2025/01/03 12:58:16 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_free_images(t_mlx *mlx)
{
	mlx_destroy_image(mlx, mlx->img->door);
	mlx_destroy_image(mlx, mlx->img->floor);
	mlx_destroy_image(mlx, mlx->img->key);
	mlx_destroy_image(mlx, mlx->img->player_down);
	mlx_destroy_image(mlx, mlx->img->player_left);
	mlx_destroy_image(mlx, mlx->img->player_down);
	mlx_destroy_image(mlx, mlx->img->player_up);
	mlx_destroy_image(mlx, mlx->img->wall);
}

int	ft_exit(t_mlx *mlx)
{
	ft_free_images(mlx);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	ft_free_map(mlx->map);
	close(mlx->fd);
	free(mlx);
	exit(0);
	return (0);
}
