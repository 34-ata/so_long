NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -L./mlx -lmlx -framework AppKit -framework OpenGL 
SRCS =  main.c get_next_line.c get_next_line_utils.c moves.c print_map.c mapcheck.c flood_fills.c


Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

OBJS= $(SRCS:.c=.o)
MINI = ./mlx/libmlx.a
RED = '\033[0;31m'

all: ${NAME}


$(MINI):
	@make -C ./mlx

$(NAME): $(MINI) $(OBJS) 
	$(CC) ${CFLAGS} $(OBJS) -o $(NAME) 
	@echo "\033[1;96mCreating Game\033[1;96m"

%.o: %.c
	@echo $(R)Complining [$<]
	@${CC} -c $^ -o $@ -Wall -Werror -Wextra -g

clean:
	@rm -rf ${OBJS}
	@echo $(R)Removed [$(OBJS)]$(B)
	@make clean -C mlx/

fclean: clean
	@rm -rf ${NAME}
	@echo $(R)Removed [$(NAME)]$(B)
	@make clean -C mlx/

re: fclean all
.PHONY: fclean re all clean