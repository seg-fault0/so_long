#include "so_long.h"


typedef struct s_data
{
    void    *mlx;
    void    *win;
}   t_data;

// Callback function to handle the close event
int close_window(t_data *data)
{
    if (data->win)
        mlx_destroy_window(data->mlx, data->win); // Destroy the window
    exit(0); // Exit the program cleanly
    return (0);
}

int main(void)
{
    t_data data;

    // Initialize MiniLibX
    data.mlx = mlx_init();

    // Create a new window
    data.win = mlx_new_window(data.mlx, 800, 600, "Close Window Example");


    // Hook the close event (17 is the destroy notify event)
    mlx_hook(data.win, 17, 0, close_window, &data);

    // Start the MiniLibX event loop
    mlx_loop(data.mlx);

    return (0);
}