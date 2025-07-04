SRC = main.c create_map.c get_next_line.c get_next_line_utils.c exits.c \
	map_checker.c path_finder.c player.c utils.c keyamount.c \
	move_allowed.c parse.c

OBJ = $(SRC:.c=.o)

NAME = so_long

LIBFT = libft

MLXFLG = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJ)
	@echo "\033[0;34m"
	@$(MAKE) -C libft 
	@cp libft/libft.a .
	@$(MAKE) -C minilibx-linux
	@cc $(FLAGS) $(OBJ) libft.a -L minilibx-linux -l mlx_Linux \
	-L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "\033[0;93mSo_Long created!!"

%.o : %.c
	@cc $(FLAGS) -I/usr/include -Iminilibx-linux -O3 -c $< -o $@

clean :
	@echo "\033[0;35m CLEANING...\033[0;34m"
	@make clean -C $(LIBFT)
	@rm -fr $(OBJ)
	@echo "\033[0;32mCLEANED\033[0;00m"

fclean : clean
	@echo "\033[0;34m"
	@rm -fr $(NAME) libft.a
	@make fclean -C $(LIBFT)
	@echo "\033[0;35mFULLY CLEANED\033[0;00m"

re : clean fclean all

.PHONY: clean fclean all re