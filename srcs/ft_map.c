/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:24:51 by wimam             #+#    #+#             */
/*   Updated: 2025/01/05 11:19:24 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_coordinates(char **map, int obg, int axis)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\n')
		{
			if (map[j][i] == obg)
				break ;
			i++;
		}
		if (map[j][i] == obg)
			break ;
		j++;
	}
	if (axis == 'x')
		return (i);
	else if (axis == 'y')
		return (j);
	return (0);
}

void	ft_free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**ft_get_map(int fd)
{
	char	*tmp_map[MAX_COL];
	char	**map;
	int		i;
	int		j;

	if (read(fd, 0, 0) < 0)
		return (NULL);
	i = 0;
	j = -1;
	tmp_map[i] = get_next_line(fd);
	while (tmp_map[i] != NULL && i < MAX_COL - 1)
	{
		i++;
		tmp_map[i] = get_next_line(fd);
	}
	map = malloc(sizeof(char *) * (i + 1));
	if (!map)
		return (NULL);
	while (++j < i)
		map[j] = tmp_map[j];
	map[i] = NULL;
	map = ft_ckeck_map(map);
	return (map);
}

void	ft_map_gen(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mlx->map[j] != NULL)
	{
		i = 0;
		while (mlx->map[j][i] != '\n')
		{
			if (mlx->map[j][i] == '1')
				ft_mlx_print_img(mlx, mlx->img->wall, i, j);
			else if (mlx->map[j][i] == 'C' && mlx->collected == 0)
				ft_mlx_print_img(mlx, mlx->img->key, i, j);
			else if (mlx->map[j][i] == 'E')
				ft_mlx_print_img(mlx, mlx->img->door, i, j);
			else
				ft_mlx_print_img(mlx, mlx->img->floor, i, j);
			i++;
		}
		j++;
	}
}
