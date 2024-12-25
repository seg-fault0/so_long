/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:33:26 by wimam             #+#    #+#             */
/*   Updated: 2024/12/25 16:33:55 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_ckeck_map(char **map)
{
	int	key;
	int	max_x;
	int	max_y;
	int	player_x;
	int	exit_x;

	key = ft_key_count(map);
	max_x = ft_get_coordinates(map, 'S', 'x');
	max_y = ft_get_coordinates(map, 'S', 'y');
	player_x = ft_get_coordinates(map, 'P', 'x');
	exit_x = ft_get_coordinates(map, 'E', 'x');
	if (key <= 0 || player_x == max_x || exit_x == max_x
		|| max_x > 60 || max_y > 32)
	{
		write(1, "ERROR : wrong map\n", 18);
		return (ft_free_map(map), NULL);
	}
	return (map);
}