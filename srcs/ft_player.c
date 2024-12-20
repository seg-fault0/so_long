#include "so_long.h"

void	ft_player_gen(w_mlx *mlx, char **map)
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
			if(map[j][i] == 'P')
			{
				ft_mlx_print_img(mlx, PLAYER_PATH, i * IMG_SIZE, j * IMG_SIZE);
				return ;
			}
			i++;
		}
		j++;
	}
}