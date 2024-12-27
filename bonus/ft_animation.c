/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:42:24 by wimam             #+#    #+#             */
/*   Updated: 2024/12/27 18:12:22 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_get_frames(t_mlx *mlx)
{
	int	size;
	mlx->anim->f1 = mlx_xpm_file_to_image(mlx->mlx, F1, &size, &size);
	mlx->anim->f2 = mlx_xpm_file_to_image(mlx->mlx, F2, &size, &size);
	mlx->anim->f3 = mlx_xpm_file_to_image(mlx->mlx, F3, &size, &size);
	mlx->anim->f4 = mlx_xpm_file_to_image(mlx->mlx, F4, &size, &size);
	mlx->anim->f5 = mlx_xpm_file_to_image(mlx->mlx, F5, &size, &size);
}

int ft_animation(void)
{
	write(1, "h\n", 1);
	return(0);
}