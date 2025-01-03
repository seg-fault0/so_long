/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:42:24 by wimam             #+#    #+#             */
/*   Updated: 2025/01/03 13:45:59 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_get_frames(t_mlx *mlx)
{
	static int	cur;
	int			size;

	cur++;
	if (cur == 5)
		cur = 0;
	mlx_destroy_image(mlx->mlx, mlx->img->fox);
	if (cur == 0)
		mlx->img->fox = mlx_xpm_file_to_image(mlx->mlx, F1, &size, &size);
	else if (cur == 1)
		mlx->img->fox = mlx_xpm_file_to_image(mlx->mlx, F2, &size, &size);
	else if (cur == 2)
		mlx->img->fox = mlx_xpm_file_to_image(mlx->mlx, F3, &size, &size);
	else if (cur == 3)
		mlx->img->fox = mlx_xpm_file_to_image(mlx->mlx, F4, &size, &size);
	else if (cur == 4)
		mlx->img->fox = mlx_xpm_file_to_image(mlx->mlx, F5, &size, &size);
	return ;
}

int	ft_animation(t_mlx *mlx)
{
	static int	i = 1;
	int			speed;

	speed = 5000;
	if (i % speed == 0)
	{
		ft_mov(mlx, 0);
		ft_get_frames(mlx);
	}
	if (i == speed * 100)
		i = 1;
	i++;
	return (0);
}
