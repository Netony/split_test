NAME = a.out
SRCS = main.c
OBJS = $(SRCS .c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
