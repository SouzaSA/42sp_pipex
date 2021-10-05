DEFAULT_GOAL:=  all

NAME		=	pipex

SRC_DIR		=	src
OBJ_DIR		=	obj
INC_DIR		=	inc
UTILS_DIR	=	utils
LIST_DIR	=	list

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
INCS		=	-I ${INC_DIR}
SAN			=	-g -fsanitize=address

LIST		=	ft_create_list.c	\
				ft_free_list.c	\
				ft_get_last_cmd.c	\
				ft_new_node.c

UTILS		=	ft_memcpy.c	\
				ft_putendl_fd.c	\
				ft_split.c	\
				ft_strdup.c	\
				ft_strjoin.c	\
				ft_strlen.c	\
				ft_strncmp.c

SRCS		=	ft_cleaner_strstr.c	\
				ft_error_handler.c	\
				ft_get_path.c	\
				ft_init_vars.c	\
				ft_main.c	\
				ft_pipex.c	\
				ft_print_error.c	\
				${ADD_UTILS_DIR}	\
				${ADD_LIST_DIR}

ADD_UTILS_DIR	=	${addprefix ${UTILS_DIR}/,${UTILS}}

ADD_LIST_DIR	=	${addprefix ${LIST_DIR}/,${LIST}}

OBJS		=	${addprefix ./${OBJ_DIR}/,${SRCS:.c=.o}}

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