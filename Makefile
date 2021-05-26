NAME = libftprintf.a

SRCS = ft_printf.c

TEST_FUNCT = main.c

OBJS = ${SRCS:.c=.o}

TST = ${TEST_FUNCT:.c=.o}

CC		= gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

$(NAME): ${OBJS}
		ar rc ${NAME} ${OBJS}

all:	${NAME}

test: $(NAME) $(TST)
	gcc -o test $(TST) $(NAME) -I./ ft_printf.h
	./test

.PHONY: clean fclean re all

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
