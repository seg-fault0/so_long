# Compiler
CC := gcc

# Source and object files
SRC := src/main.c
OBJ_DIR := obj
OBJ := $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

# Output executable
NAME := Prog

# Includes
INCLUDES := -I includes/

# MiniLibX libraries and frameworks for macOS
MLX := -lmlx -framework OpenGL -framework AppKit

# MiniLibX libraries for Linux (comment the line above and uncomment below for Linux)
# MLX := -lmlx -lXext -lX11 -lm

# Rules
all: $(NAME)

# Create executable
$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX) -o $(NAME)

# Compile .c files into .o files in the obj directory
$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) -c $< -o $@ $(INCLUDES)

# Create the obj directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
