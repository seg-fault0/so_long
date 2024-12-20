#include "so_long.h"

int main(int argc, char *argv[])
{
	char **map;

	map = get_map(argv[1]);

	for(int i = 0; map[i] != NULL; i++)
	{
		for(int j = 0; map[i][j] != '\n'; j++)
			printf("%c", map[i][j]);
		write(1, "\n",1);
	}
}