#include "mlx.h"
#include <unistd.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
}	t_data;

int	update(t_data *data)
{
	static int	x = 10;

	mlx_clear_window(data->mlx, data->win);
	mlx_string_put(data->mlx, data->win, x, 10, 0xFFFFFF, "Hello, MLX!");
	x += 10;
	if (x > 800)
		x = 10;
	return (0);  // Return 0 to match the expected function signature
}


int	main(void)
{
	void	*mlx;
	void	*win;
	t_data	data;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "MLX Animation");

	data.mlx = mlx;
	data.win = win;

	mlx_loop_hook(mlx, update, &data);
	mlx_loop(mlx);

	return (0);
}