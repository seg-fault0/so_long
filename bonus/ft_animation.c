/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:42:24 by wimam             #+#    #+#             */
/*   Updated: 2024/12/29 11:24:26 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_get_frames(t_mlx *mlx)
{
	int			size;
	static	int cur;

	return ;
}

int ft_animation(void)
{
	static int i = 1;
	int speed = 3000;
	if(i % speed == 0)
//		write(1, "h\n", 1);
	if(i == speed * 100)
		i = 1;
	i++;
	return(0);
}