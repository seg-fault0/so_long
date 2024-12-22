/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:24:22 by wimam             #+#    #+#             */
/*   Updated: 2024/12/22 16:39:25 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx);
	exit(0);
	return (0);
}

int	ft_key_count(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\n')
		{
			if (map[j][i] == 'C')
				count++;
			i++;
		}
		j++;
	}
	return (count);
}
