DEFAULT_GOAL:=  all

NAME		=	pipex

SRC_DIR		=	./src
OBJ_DIR		=	./obj
INC_DIR		=	./inc

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
INCS		=	-I ${INC_DIR}
SAN			=	-g3 -fsanitize=address

SRCS		=	ft_error_handler.c	\
				ft_pipex.c	\
				ft_print_help.c	\
				ft_putendl_fd.c	\
				ft_split.c	\
				ft_strncmp.c

OBJS		=	${addprefix ${OBJ_DIR}/,${SRCS:.c=.o}}

RM			=	@rm -rf

DIR_GUARD	=	@mkdir -p ${@D}

${OBJ_DIR}/%.o:	${SRC_DIR}/%.c
			${DIR_GUARD}
			${CC} ${CFLAGS} ${INCS} -c $< -o $@

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${INCS}

all:		${NAME}

bonus:		${NAME}

san:		${OBJS}
			${CC} ${SAN} ${CFLAGS} ${OBJS} -o ${NAME} ${INCS}

clean:
			${RM} ${OBJ_DIR}

fclean: 	clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all bonus san clean fclean re