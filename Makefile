SRC = srcs/*.c
L = -L ./ -lmlx_Linux -lX11 -lXext
I = -I ./
NAME = so_long
FLAGS = -Wall -Wextra -Werror

all: mlx
	cc $(FLAGS) $(SRC) $(I) $(L) -o $(NAME)

mlx:
	tar -xvzf minilibx-linux.tgz
	cd minilibx-linux && make
	cd ..
	mv minilibx-linux/libmlx_Linux.a .
	mv minilibx-linux/mlx.h .

clean:
	rm -fr minilibx-linux

fclean: clean
	rm -f *.a
	rm -f mlx.h

re : fclean all

.PHONEY: clean mlx