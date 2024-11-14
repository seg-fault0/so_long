#include "so_long.h"

int		player_mouvement(player_t player, int keycode)
{
	if (keycode == 0)
		player.x_axis -= 20;
	else if(keycode == 1)
		player.x_axis += 20;
	else if(keycode == 2)
		player.y_axis += 20;
	else if(keycode == 3)
		player.y_axis -= 20;
	return (0);
}