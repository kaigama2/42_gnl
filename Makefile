NAME = gnl
GCC = gcc
CFLAG = -Wall -Wextra -Werror

SRCS = ft_get_next_line.c \
	 ft_putstr.c \
	 
OBJS = ${SRCS:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
	${GCC} ${OBJS} -o $@

%.o:	%.c
	${GCC} ${CFLAG} -o $@ -c $<

clean:	
	@rm -f ${OBJS}

fclean:	clean
	@rm -f ${NAME}

re:		fclean all

.Phony: all clean fclean re