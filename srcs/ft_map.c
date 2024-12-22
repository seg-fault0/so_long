/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimamgmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:24:51 by wimam             #+#    #+#             */
/*   Updated: 2024/12/22 09:35:39 by wimam            ###   ########.fr       */
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
}

char	**ft_get_map(int fd)
{
	char	*tmp_map[MAX_COL];
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = -1;
	tmp_map[i] = get_next_line(fd);
	while (tmp_map[i] != NULL && i < MAX_COL - 1)
	{
		i++;
		tmp_map[i] = get_next_line(fd);
	}
	map = malloc(sizeof(char *) * (i + 1));
	if (map == NULL)
		return (NULL);
	while (++j < i)
		map[j] = tmp_map[j];
	map[i] = NULL;
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
				ft_mlx_print_img(mlx, WALL_PATH, i, j);
			else if (mlx->map[j][i] == 'C' && mlx->collected == 0)
				ft_mlx_print_img(mlx, KEY_PATH, i, j);
			else if (mlx->map[j][i] == 'E')
				ft_mlx_print_img(mlx, DOOR_PATH, i, j);
			else if (mlx->map[j][i] == 'B')
				ft_mlx_print_img(mlx, FOX_PATH, i, j);
			else
				ft_mlx_print_img(mlx, FLOOR_PATH, i, j);
			i++;
		}
		j++;
	}
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

void	ft_free_map(char **map)
{
	int	i;

	if (!map)
		return;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}