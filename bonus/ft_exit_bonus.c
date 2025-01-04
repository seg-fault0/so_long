/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:24:22 by wimam             #+#    #+#             */
/*   Updated: 2025/01/04 18:06:46 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free_images(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img->door);
	mlx_destroy_image(mlx->mlx, mlx->img->floor);
	mlx_destroy_image(mlx->mlx, mlx->img->key);
	mlx_destroy_image(mlx->mlx, mlx->img->player_down);
	mlx_destroy_image(mlx->mlx, mlx->img->player_left);
	mlx_destroy_image(mlx->mlx, mlx->img->player_right);
	mlx_destroy_image(mlx->mlx, mlx->img->player_up);
	mlx_destroy_image(mlx->mlx, mlx->img->wall);
	mlx_destroy_image(mlx->mlx, mlx->img->fox);
}

int	ft_exit(t_mlx *mlx)
{
	ft_free_images(mlx);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	ft_free_map(mlx->map);
	close(mlx->fd);
	free(mlx->img);
	free(mlx);
	exit(0);
	return (0);
}
