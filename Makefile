SRC =	srcs/ft_check.c				\
		srcs/ft_exit.c				\
		srcs/ft_input.c				\
		srcs/ft_map.c				\
		srcs/ft_mlx.c				\
		srcs/ft_utils.c				\
		srcs/get_next_line.c		\
		srcs/get_next_line_utils.c	\
		srcs/main.c					\

BSRC = 	bonus/ft_check.c			\
		bonus/ft_exit.c				\
		bonus/ft_input.c			\
		bonus/ft_map.c				\
		bonus/ft_mlx.c				\
		bonus/ft_utils.c			\
		bonus/get_next_line.c		\
		bonus/get_next_line_utils.c	\
		bonus/main.c				\

OBG = $(SRC:.c=.o)
BOBG = $(BSRC:.c=.o)

NAME = so_long
BNAME = so_long_bonus
L = -L ./ -lmlx_Linux -lX11 -lXext
I = -I ./includes/
FLAGS = -Wall -Wextra -Werror

all: $(NAME)
bonus: $(BNAME)

$(NAME): $(OBG)
	cc $(OBG) $(L) -o $@

$(BNAME): $(BOBG)
	cc $(BOBG) $(L) -o $@

%.o: %.c
	cc -c $(FLAGS) $(I) $^ -o $@

clean:
	rm -f $(OBG)

fclean: clean
	rm -f $(NAME)

bclean:
	rm -f $(BOBG) $(NAME)

re: clean all

.PHONEY: clean mlx



mlx:
	rm -fr minilibx-linux
	tar -xvzf minilibx-linux.tgz
	cd minilibx-linux && make
	cd ..
	mv minilibx-linux/libmlx_Linux.a .
	mv minilibx-linux/mlx.h ./includes/.
	rm -fr minilibx-linux
lldb:
	clang -g -I ./includes/ srcs/*.c -L ./ -lmlx_Linux -lX11 -lXext -o debugProg