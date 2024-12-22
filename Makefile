# Source files and other variables
SRC = srcs/*.c
L = -L ./ -lmlx_Linux -lX11 -lXext
I = -I ./
NAME = so_long

# All target: compiles everything
all: mlx
	clang -g $(SRC) $(I) $(L) -o $(NAME)

# Compile mlx
mlx:
	tar -xvzf minilibx-linux.tgz
	cd minilibx-linux && make
	cd ..
	mv minilibx-linux/libmlx_Linux.a .
	mv minilibx-linux/mlx.h .

clean:
	rm -f *.a
	rm -f mlx.h
	rm -f $(NAME)

fclean: clean
	rm -fr minilibx-linux

re : fclean all

.PHONEY: clean mlx