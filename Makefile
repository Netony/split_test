NAME = a.out
SRCS = main.c
LIBFT = libft/libft.a
OBJ_DIR = objs

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
CFLAGS = -Wall -Werror -Wextra -I libft/incs

all : $(NAME)
	./$(NAME)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ -lft -Llibft

$(LIBFT) :
	$(MAKE) -j3 -C libft

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

