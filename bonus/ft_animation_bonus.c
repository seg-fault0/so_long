/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:42:24 by wimam             #+#    #+#             */
/*   Updated: 2025/01/05 08:52:37 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_fox_mov(t_mlx *mlx, char **map)
{
	int			i;
	int			j;
	static int	dir = 1;

	i = -1;
	while (map[++i] != NULL)
	{
		j = -1;
		while (map[i][++j] != '\n')
		{
			if (map[i][j] == 'B'
				&& (map[i][j + dir] == '0' || map[i][j + dir] == 'P'))
			{
				map[i][j] = '0';
				map[i][j + dir] = 'B';
				j++;
			}
			if (map[mlx->py][mlx->px] == 'B')
			{
				write(1, "You Lost! \n", 11);
				ft_exit(mlx);
			}
		}
	}
	dir *= -1;
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
		ft_fox_mov(mlx, mlx->map);
	if (i == anim_speed * 1000)
		i = 1;
	i++;
	return (0);
}
