/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:42:24 by wimam             #+#    #+#             */
/*   Updated: 2024/12/29 15:23:40 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_get_frames(t_mlx *mlx)
{
	int			size;
	static	int cur;

	cur++;
	if(cur == 5)
		cur = 0;
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

int ft_animation(t_mlx *mlx)
{
	static int i = 1;
	int speed = 5000;
	if(i % speed == 0)
	{
		ft_get_frames(mlx);
		ft_map_gen(mlx);
	}
	if(i == speed * 100)
		i = 1;
	i++;
	return(0);
}