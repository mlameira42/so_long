SRC = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c 
BSRC = \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c 
OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

%.o : %.c
	@cc  $(FLAGS) -c $?

$(NAME): $(OBJ)
	@echo "\033[0;35mCreating LIBFT..."
	@ar -r $@ $? | printf "" 
	@echo "\033[0;33mCreated!\033[0;34m"

bonus: $(OBJ) $(BOBJ)
	@ar -r $(NAME) $?

all: $(NAME)
clean :
	@echo "\033[0;35mCleaning libft.."
	@rm -fr $(OBJ) $(BOBJ) 
	@echo "\033[0;34mCleaned"
fclean: clean
	@echo "\033[0;35m"
	@rm -fr $(NAME)
	@echo "\033[0;34mFully cleaned Libft"
re: clean  fclean all
PHONY: clean fclean bonus all re
