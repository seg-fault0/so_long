# Source files and other variables
SRC = srcs/*.c
I = -I includes/
L = -L libraries/ -lmlx_Linux -lX11 -lXext
NAME = so_long

# All target: compiles everything
all: mlx
	cc $(I) $(SRC) $(L) -o $(NAME)

# Compile mlx
mlx:
	tar -xvzf minilibx-linux.tgz
	cd minilibx-linux && make
	cd ..
	mv minilibx-linux/*.a libraries/
	mv minilibx-linux/mlx.h includes/

clean:
	rm -f libraries/*
	rm -f includes/mlx.h
	rm -f $(NAME)

fclean: clean
	rm -fr minilibx-linux

re : fclean all

.PHONEY: clean mlx