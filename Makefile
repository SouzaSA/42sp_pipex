# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 10:58:35 by sde-alva          #+#    #+#              #
#    Updated: 2021/12/04 11:01:15 by sde-alva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEFAULT_GOAL:=  all

NAME		=	pipex
NAME_BONUS	=	pipex_bonus

SRC_DIR		=	src
OBJ_DIR		=	obj
BIN_DIR		=	bin
INC_DIR		=	inc
UTILS_DIR	=	utils
SHARED_DIR	=	shared

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
INCS		=	-I ${SRC_DIR}/${GNL_DIR} -I ${INC_DIR}
SAN			=	-g -fsanitize=address

SHARED		=	ft_checker_slash.c	\
				ft_cleaner_strstr.c	\
				ft_error_msg.c	\
				ft_get_cmd_path.c	\
				ft_get_path.c	\
				ft_params_split.c

UTILS		=	ft_get_next_line.c	\
				ft_memcpy.c	\
				ft_putendl_fd.c	\
				ft_split.c	\
				ft_strchr.c	\
				ft_strcmp.c	\
				ft_strdup.c	\
				ft_strjoin.c	\
				ft_strlen.c	\
				ft_strncmp.c	\
				ft_strrchr.c	\
				ft_substr.c	\
				ft_strtrim.c

SRCS		=	ft_main.c	\
				ft_forker.c	\
				ft_pipex.c	\
				${ADD_SHARED_DIR}	\
				${ADD_UTILS_DIR}

BONUS		=	ft_main_bonus.c	\
				ft_forker_bonus.c	\
				ft_here_doc_bonus.c	\
				ft_pipex_bonus.c	\
				${ADD_SHARED_DIR}	\
				${ADD_UTILS_DIR}

ADD_UTILS_DIR	=	${addprefix ${UTILS_DIR}/,${UTILS}}

ADD_SHARED_DIR	=	${addprefix ${SHARED_DIR}/,${SHARED}}

OBJS		=	${addprefix ./${OBJ_DIR}/,${SRCS:.c=.o}}

BONUS_OBJS	=	${addprefix ./${OBJ_DIR}/,${BONUS:.c=.o}}

MANDATORY_FILE	= ${addprefix ${BIN_DIR}/,${NAME}}

BONUS_FILE	= ${addprefix ${BIN_DIR}/,${NAME_BONUS}}

RM			=	@rm -rf

DIR_GUARD	=	@mkdir -p ${@D}

FILE_SIZE	=	stat -c\%s

${OBJ_DIR}/%.o:	${SRC_DIR}/%.c
			${DIR_GUARD}
			${CC} ${CFLAGS} ${INCS} -c $< -o $@

${NAME}:	${MANDATORY_FILE}

${MANDATORY_FILE}:	${OBJS}
			${DIR_GUARD}
			${CC} ${CFLAGS} ${OBJS} ${INCS} -o ${MANDATORY_FILE}
			${RM} ${BONUS_FILE}
			cp ${MANDATORY_FILE} ${NAME}

${NAME_BONUS}:	${BONUS_FILE}

${BONUS_FILE}:	${BONUS_OBJS}
			${DIR_GUARD}
			${CC} ${CFLAGS} ${BONUS_OBJS} ${INCS} -o ${BONUS_FILE}
			${RM} ${MANDATORY_FILE}
			cp ${BONUS_FILE} ${NAME}

all:		${NAME}

bonus:		${NAME_BONUS}

san:		${OBJS}
			${CC} ${SAN} ${CFLAGS} ${OBJS} -o ${NAME} ${INCS}

bonus_san:	${BONUS_OBJS}
			${CC} ${SAN} ${CFLAGS} ${BONUS_OBJS} -o ${NAME} ${INCS}

clean:
			${RM} ${OBJ_DIR}
			${RM} ${BIN_DIR}

fclean: 	clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all bonus san clean fclean re ${NAME}
