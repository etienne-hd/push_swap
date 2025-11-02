CC=cc
NAME = push_swap
SRC_DIR = srcs/
SRCS = $(SRC_DIR)push_swap.c \
		$(SRC_DIR)parser.c \
		$(SRC_DIR)stack.c \
		$(SRC_DIR)stack_swap.c \
		$(SRC_DIR)stack_push.c \
		$(SRC_DIR)stack_display.c \
		$(SRC_DIR)stack_utils.c \
		$(SRC_DIR)stack_rotate.c \
		$(SRC_DIR)stack_reverse_rotate.c \
		$(SRC_DIR)solver.c \
		$(SRC_DIR)solver_utils.c

OBJ_DIR = objs/
OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
LIBFT = ./libft/libft.a

CFLAGS = -Wall -Wextra -Werror -I includes -I libft -I libft/ft_printf/includes
LDFLAGS = $(LIBFT)

all:$(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -c -o $@

$(LIBFT):
	$(MAKE) -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C libft clean

run: all
	./$(NAME) $(ARGS)

run2: all
	valgrind --show-leak-kinds=all --leak-check=full ./$(NAME) $(ARGS)

re: fclean all

.PHONY: all fclean clean run run2 re
