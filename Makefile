SRC =	srcs/ft_check.c				\
		srcs/ft_exit.c				\
		srcs/ft_input.c				\
		srcs/ft_map.c				\
		srcs/ft_mlx.c				\
		srcs/ft_utils.c				\
		srcs/get_next_line.c		\
		srcs/get_next_line_utils.c	\
		srcs/main.c					\

OBG = $(SRC:.c=.o)

L = -L ./ -lmlx_Linux -lX11 -lXext
I = -I ./includes/
NAME = so_long
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBG)
	cc $(OBG) $(L) -o $@

%.o: %.c
	cc -c $(FLAGS) $(I) $^ -o $@

clean:
	rm -f $(OBG)

re: clean all

mlx:
	rm -fr minilibx-linux
	tar -xvzf minilibx-linux.tgz
	cd minilibx-linux && make
	cd ..
	mv minilibx-linux/libmlx_Linux.a .
	mv minilibx-linux/mlx.h ./includes/.
	rm -fr minilibx-linux

.PHONEY: clean mlx

lldb:
	clang -g -I ./includes/ srcs/*.c -L ./ -lmlx_Linux -lX11 -lXext -o debugProg