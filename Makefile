I = -I includes/
L = -L libraries/ -lmlx_Linux -lX11 -lXext

src = srcs/*.c

name = so_long

all:
	cc $(I) $(src) $(L) -o $(name)
	./$(name)

lldb:
	cc $(I) $(src) $(L) -g

key:
	cc $(I) ./.Trash/key.c $(L) 