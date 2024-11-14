SRC = 	src/main.c		\
		src/utils.c		\
		src/player.c	\
		src/mouvement.c	\

OBJ = $(SRC:src/%.c=obj/%.o)

INCLUDES = -I includes/

LINUX_LINK = -L ./libraries -lmlx -lX11 -lXext

MAC_LINK = -L ./libraries -lmlx -framework OpenGL -framework AppKit

GAME = prog

all:
	@echo 'make mac || make linux'

mac: $(OBJ)
	cc $(OBJ) $(MAC_LINK) -o $(GAME)

linux: $(OBJ)
	cc $(OBJ) $(LINUX_LINK) -o $(GAME)

obj/%.o: src/%.c | obj
	cc -c $(INCLUDES)  $< -o $@

obj:
	mkdir -p obj

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(GAME)

re: fclean all

