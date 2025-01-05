/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:07:28 by wimam             #+#    #+#             */
/*   Updated: 2025/01/05 09:08:28 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_point
{
	int	x;
	int	y;
}t_point;

char	**ft_get_map_cpy(char **map, int max_y, int max_x)
{
	char	**map_cpy;
	int		i;
	int		j;

	map_cpy = malloc(8 * max_y);
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		map_cpy[i] = malloc(max_x);
		while (map[i][j] != '\n')
		{
			map_cpy[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	return (map_cpy);
}

void	fill(char **tab, t_point size, t_point cur, int *ek)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] == '1')
		return ;
	if (tab[cur.y][cur.x] == 'E' || tab[cur.y][cur.x] == 'C')
		*ek += 1;
	tab[cur.y][cur.x] = '1';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, ek);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, ek);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, ek);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, ek);
}

int	ft_check_path(t_mlx *mlx)
{
	t_point	size;
	t_point	start;
	char	**map;
	int		ek;

	size.x = ft_get_coordinates(mlx->map, 'S', 'x');
	size.y = ft_get_coordinates(mlx->map, 'S', 'y');
	start.x = ft_get_coordinates(mlx->map, 'P', 'x');
	start.y = ft_get_coordinates(mlx->map, 'P', 'y');
	ek = 0;
	map = ft_get_map_cpy(mlx->map, size.y + 1, size.x + 1);
	fill(map, size, start, &ek);
	ft_free_map(map);
	if (ek != mlx->keys + 1)
	{
		write(2, "EROOR\n", 6);
		return (1);
	}
	return (0);
}
