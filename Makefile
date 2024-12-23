SRC = srcs/.c
L = -L ./ -lmlx_Linux -lX11 -lXext
I = -I ./
NAME = so_long
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): mlx
	cc $(FLAGS) $(SRC) $(I) $(L) -o $(NAME)

clean:
	rm -fr minilibx-linux

fclean: clean
	rm -f *.a
	rm -f mlx.h

re : fclean all

mlx:
	tar -xvzf minilibx-linux.tgz
	cd minilibx-linux && make
	cd ..
	mv minilibx-linux/libmlx_Linux.a .
	mv minilibx-linux/mlx.h .

.PHONEY: clean mlx
