NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

SRC = push_swap.c push.c atoi.c butterfly.c ft_lst_func.c ft_split.c validation.c \
		reverse_rotate.c rotate.c swap_for_2.c sorting.c utils.c

OBJS = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} 
	${CC} ${FLAGS} ${OBJS} -o ${NAME} 

%.o:%.c push_swap.h Makefile
	${CC} ${FLAGS} -c  $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re