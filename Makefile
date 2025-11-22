CC=cc
NAME = push_swap
SRC_DIR = src/
SRCS = $(SRC_DIR)push_swap.c \
		$(SRC_DIR)parser.c \
		$(SRC_DIR)stack/stack.c \
		$(SRC_DIR)stack/stack_display.c \
		$(SRC_DIR)stack/stack_utils.c \
		$(SRC_DIR)stack/instruction/stack_swap.c \
		$(SRC_DIR)stack/instruction/stack_push.c \
		$(SRC_DIR)stack/instruction/stack_rotate.c \
		$(SRC_DIR)stack/instruction/stack_reverse_rotate.c \
		$(SRC_DIR)solver/solver.c \
		$(SRC_DIR)solver/solver_utils.c

OBJ_DIR = .build/
OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
LIBFT = ./libft/libft.a

CFLAGS = -Wall -Wextra -Werror -I include -I libft -I libft/ft_printf/includes
LDFLAGS = $(LIBFT)

all:$(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)stack/
	@mkdir -p $(OBJ_DIR)stack/instruction
	@mkdir -p $(OBJ_DIR)solver/
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
