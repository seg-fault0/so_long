/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:33:26 by wimam             #+#    #+#             */
/*   Updated: 2025/01/05 09:07:20 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_map_border(char **map, int max_x, int max_y)
{
	int	i;
	int	j;

	i = 0;
	while (map[0][i] != '\n' && map[max_y][i] != '\n')
	{
		if (map[0][i] != '1' || map[max_y][i] != '1')
			return (1);
		i++;
	}
	i = -1;
	while (++i < max_y)
		if (map[i][0] != '1')
			return (1);
	j = -1;
	while (++j <= max_y)
	{
		i = -1;
		while (map[j][++i] != '\n')
			if ((i != max_x - 1 || map[j][i] != '1') && map[j][i + 1] == '\n')
				return (1);
	}
	return (0);
}

int	ft_check_double(char **map)
{
	int	i;
	int	j;
	int	e;
	int	p;

	e = 0;
	p = 0;
	j = 0;
	while (map[++j] != NULL)
	{
		i = -1;
		while (map[j][++i] != '\n')
		{
			if (map[j][i] == 'P')
				p++;
			else if (map[j][i] == 'E')
				e++;
		}
	}
	if (p != 1 || e != 1)
		return (1);
	return (0);
}

int	ft_check_map_components(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[++j] != NULL)
	{
		i = -1;
		while (map[j][++i] != '\n')
		{
			if (map[j][i] != 'C' && map[j][i] != '1' && map[j][i] != '0'
				&& map[j][i] != 'E' && map[j][i] != 'P' && map[j][i] != 'B')
				return (1);
		}
	}
	return (ft_check_double(map));
}

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
		|| max_x > 60 || max_y > 32 || ft_check_map_components(map)
		|| ft_check_map_border(map, max_x, max_y - 1))
	{
		write(2, "ERROR : wrong map\n", 18);
		return (ft_free_map(map), NULL);
	}
	return (map);
}

int	ft_check_extension(char *path)
{
	int		len;
	int		max;
	int		i;
	char	*extension;

	if (!path)
		return (1);
	extension = ".ber";
	len = ft_strlen(path);
	if (len < 4)
		return (1);
	max = len - 4;
	i = 0;
	while (max + i < len)
	{
		if (path[max + i] != extension[i])
		{
			write(2, "Error\n", 7);
			return (1);
		}
		i++;
	}
	return (0);
}
