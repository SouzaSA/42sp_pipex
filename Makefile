DEFAULT_GOAL:=  all

NAME		=	pipex

SRC_DIR		=	src
OBJ_DIR		=	obj
INC_DIR		=	inc
UTILS_DIR	=	utils
LIST_DIR	=	list
SHARED_DIR	=	shared

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
INCS		=	-I ${SRC_DIR}/${GNL_DIR} -I ${INC_DIR}
SAN			=	-g -fsanitize=address

LIST		=	ft_create_list.c	\
				ft_free_list.c	\
				ft_get_last_cmd.c	\
				ft_init_cmd.c	\
				ft_new_node.c

SHARED		=	ft_checker_slash.c	\
				ft_cleaner_strstr.c	\
				ft_error_handler.c	\
				ft_forker.c	\
				ft_get_path.c	\
				ft_print_error.c

UTILS		=	get_next_line_utils.c	\
				get_next_line.c	\
				ft_memcpy.c	\
				ft_putendl_fd.c	\
				ft_putstr_fd.c	\
				ft_split.c	\
				ft_strchr.c	\
				ft_strcmp.c	\
				ft_strdup.c	\
				ft_strjoin.c	\
				ft_strlen.c	\
				ft_strncmp.c

SRCS		=	ft_init_vars.c	\
				ft_main.c	\
				ft_pipex.c	\
				${ADD_SHARED_DIR}	\
				${ADD_UTILS_DIR}	\
				${ADD_LIST_DIR}

BONUS		=	ft_init_vars_bonus.c	\
				ft_main_bonus.c	\
				ft_pipex_bonus.c	\
				${ADD_SHARED_DIR}	\
				${ADD_UTILS_DIR}	\
				${ADD_LIST_DIR}

ADD_UTILS_DIR	=	${addprefix ${UTILS_DIR}/,${UTILS}}

ADD_LIST_DIR	=	${addprefix ${LIST_DIR}/,${LIST}}

ADD_SHARED_DIR	=	${addprefix ${SHARED_DIR}/,${SHARED}}

OBJS		=	${addprefix ./${OBJ_DIR}/,${SRCS:.c=.o}}

BONUS_OBJS	=	${addprefix ./${OBJ_DIR}/,${BONUS:.c=.o}}

RM			=	@rm -rf

DIR_GUARD	=	@mkdir -p ${@D}

${OBJ_DIR}/%.o:	${SRC_DIR}/%.c
			${DIR_GUARD}
			${CC} ${CFLAGS} ${INCS} -c $< -o $@

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} ${INCS} -o ${NAME}

all:		${NAME}

bonus:		${BONUS_OBJS}
			${CC} ${CFLAGS} ${BONUS_OBJS} -o ${NAME} ${INCS}

san:		${OBJS}
			${CC} ${SAN} ${CFLAGS} ${OBJS} -o ${NAME} ${INCS}

bonus_san:	${BONUS_OBJS}
			${CC} ${SAN} ${CFLAGS} ${BONUS_OBJS} -o ${NAME} ${INCS}

clean:
			${RM} ${OBJ_DIR}

fclean: 	clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all bonus san clean fclean re
