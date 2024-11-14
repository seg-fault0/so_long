SRC = src/main.c

OBJ = $(SRC:src/%.c=obj/%.o)

INCLUDES = -I includes/

LINK = -L ./libraries -lmlx -lX11 -lXext

GAME = a.out

all: $(GAME)

$(GAME): $(OBJ)
	cc $(OBJ) $(LINK) -o $@

obj/%.o: src/%.c | obj
	cc -c $(INCLUDES)  $< -o $@

obj:
	mkdir -p obj

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(GAME)

re: fclean all

