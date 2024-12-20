I = -I includes/
L = -L libraries/ -lmlx_Linux -lX11 -lXext -lgnl

src = srcs/*.c

name = so_long

all:
	cc $(I) $(src) $(L) -o $(name)
	./$(name) "maps/map.ber"

lldb:
	clang -g $(I) $(src) $(L)
	lldb ./a.out

key:
	cc $(I) ./.Trash/key.c $(L) 