#include "so_long.h"

int ft_getcoordinates(char **map, int obg, int axis)
{
	int	i;
	int j;

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
		return (j);
	else if(axis == 'y')
		return (i);
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

void	ft_map_gen(w_mlx *mlx)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (mlx->map[j] != NULL)
	{
		i = 0;
		while (mlx->map[j][i] != '\n')
		{
			if(mlx->map[j][i] == '1')
				ft_mlx_print_img(mlx, WALL_PATH, i * IMG_SIZE, j * IMG_SIZE);
			else if(mlx->map[j][i] == 'C')
				ft_mlx_print_img(mlx, KEY_PATH, i * IMG_SIZE, j * IMG_SIZE);
			else if(mlx->map[j][i] == 'E')
				ft_mlx_print_img(mlx, DOOR_PATH, i * IMG_SIZE, j * IMG_SIZE);
			else
				ft_mlx_print_img(mlx, FLOOR_PATH, i * IMG_SIZE, j * IMG_SIZE);
			i++;
		}
		j++;
	}
}
