#include "so_long.h"

char	**get_map(char *path)
{
	int fd = open(path, O_RDONLY);
	char *tmp_map[MAX_COL];
	char **map;

	int i = 0;
	tmp_map[i] = get_next_line(fd);
	while (tmp_map[i] != NULL)
	{
		tmp_map[i++] = get_next_line(fd);
		i++;
	}
	
	map = malloc(sizeof(char *) * i);

	for(int j = 0; j <= i; j++)
		*map = tmp_map[j];

	return (map);
}