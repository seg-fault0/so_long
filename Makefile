I = -I includes/
L = -L libraries/ -lmlx_Linux -lX11 -lXext -lgnl

src = srcs/*.c

name = so_long

all:
	cc $(I) $(src) $(L) -o $(name)
	./$(name) 'maps/map.ber'

lldb:
	cc $(I) $(src) $(L) -g

key:
	cc $(I) ./.Trash/key.c $(L) 