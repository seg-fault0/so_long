#include "so_long.h"

char	**get_map(int fd)
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
