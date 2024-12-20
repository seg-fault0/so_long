#include "so_long.h"

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

void	ft_map_gen(w_mlx *mlx, char **map)
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
			if(map[j][i] == '1')
				ft_mlx_print_img(mlx, WALL_PATH, i * IMG_SIZE, j * IMG_SIZE);
			else if(map[j][i] == '0')
				ft_mlx_print_img(mlx, FLOOR_PATH, i * IMG_SIZE, j * IMG_SIZE);
			else if(map[j][i] == 'P')
				ft_mlx_print_img(mlx, PLAYER_PATH, i * IMG_SIZE, j * IMG_SIZE);
			else if(map[j][i] == 'C')
				ft_mlx_print_img(mlx, KEY_PATH, i * IMG_SIZE, j * IMG_SIZE);
			i++;
		}
		j++;
	}
}
