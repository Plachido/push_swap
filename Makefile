NAME = push_swap

LIBFT = libft/libft.a

FLAGS = -Wall -Wextra -Werror -fsanitize=address -g
SRCS = 	$(shell find src -name "*.c")

OBJ = $(@SRCS:.c=.o)
CC	=	gcc

$(NAME): $(OBJ) $(LIBFT)
	@echo "[Removing last version...]"
	@rm -rf push_swap
	@echo "[push_swap compilation...]"
	@$(CC) $(SRCS) $(FLAGS) $(LIBFT) -o $(NAME)
	@echo "[Done!]"
	@$(MAKE) clean

$(LIBFT):
	@echo "[compiling libft...]"
	@$(MAKE) bonus -C ./libft
	@$(MAKE) clean -C ./libft

all : $(NAME)

norm:
	@norminette $(FILES)

clean:
	@rm -rf $(OBJ)
	@$(MAKE) clean -C ./libft

fclean: clean
	@rm -rf $(NAME) $(LIBFT) $(MLX)
	@$(MAKE) fclean -C ./libft

re : fclean all
