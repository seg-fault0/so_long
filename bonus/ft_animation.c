/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:42:24 by wimam             #+#    #+#             */
/*   Updated: 2025/01/04 09:28:16 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_fox_mov(t_mlx *mlx)
{
	int			i;
	int			j;
	static int	dir;

	i = 0;
	while (mlx->map[i] != NULL)
	{
		j = 0;
		while (mlx->map[i][j] != '\n')
		{
			if(mlx->map[i][j] == 'B' && mlx->map[i][j+1] == '0' && dir == 0)
			{
				mlx->map[i][j] = '0';
				mlx->map[i][++j] = 'B';
				dir = 1;
			}
			else if(mlx->map[i][j] == 'B' && mlx->map[i][j-1] == '0' && dir == 1)
			{
				mlx->map[i][j] = '0';
				mlx->map[i][--j] = 'B';
				dir = 0;
			}
			j++;
		}
		i++;
	}	
}

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
	int			anim_speed;
	int			fox_mv_speed;

	anim_speed = 5000;
	fox_mv_speed = 50000;
	if (i % anim_speed == 0)
	{
		ft_mov(mlx, 0);
		ft_get_frames(mlx);
	}
	if (i % fox_mv_speed == 0)
		ft_fox_mov(mlx);
	if (i == anim_speed * 1000)
		i = 1;
	i++;
	return (0);
}
