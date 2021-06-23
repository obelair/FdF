# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 12:38:13 by obelair           #+#    #+#              #
#    Updated: 2021/06/23 11:01:05 by obelair          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# === Name === #

NAME		=	fdf
LINUX		=	0

# === Directories === #

MINILIBX_OS_X	= minilibx-macos
MINILIBX_LINUX	= minilibx-linux

PATH_LIBFT	=	libft
PATH_HEADERS=	incs
PATH_SRCS	=	srcs
PATH_OBJS	=	objs

ifeq (${LINUX},0)
PATH_MLX	= ${MINILIBX_OS_X}
MLX			= libmlx.dylib
else
PATH_MLX	= ${MINILIBX_LINUX}
MLX			= libmlx.a
endif


# === Compil === #

CC			=	gcc
RENAME		=	-o ${NAME}
CFLAGS		=	-Wall -Werror -Wextra -g3 
INCS		=	-I${PATH_HEADERS} -I${PATH_LIBFT}/${PATH_HEADERS} -I${PATH_MLX}
LIBS		=	${MLX} ${PATH_LIBFT}/libft.a
ifeq ($(LINUX),1)
LIBS		+=	-lm -lXext -lX11
endif
RM			=	rm -rf

# === Sources === #

SRCS		=	${addprefix ${PATH_SRCS}/, main.c draw.c error.c init.c read.c rgb.c data.c}

# === Objects === #

OBJS		=	${addprefix ${PATH_OBJS}/, ${notdir ${SRCS:.c=.o}}}

# === Include === #

HEADERS		=	${addprefix ${PATH_HEADERS}/, fdf.h}

# === Colors === #

_END		=	\033[0m
_BOLD		=	\033[1m
_DIM		=	\033[2m
_UNDERLINE	=	\033[3m

_RED		=	\033[31m
_GREEN		=	\033[32m
_YELLOW		=	\033[33m
_CYAN		=	\033[36m
_LIGHTGRAY	=	\033[37m
_DARKGRAY	=	\033[90m
_LIGHTRED	=	\033[91m

# === Default === #

all:	init ${NAME}

# === Commands === #

${PATH_OBJS}/%.o: ${PATH_SRCS}/%.c ${HEADERS}
	@ echo " ${_GREEN}${_DIM}\\\\\ ${_END}${_GREEN}Compilation done!${_DIM} //${_CYAN}   --->   ${_END}${_YELLOW}| ${_BOLD}${_CYAN}$<${_END} "
	@ ${CC} ${CFLAGS} -c $< -o $@ ${INCS}

init:	
	@ ${shell mkdir -p ${PATH_OBJS}}
	@ ${MAKE} -C ${PATH_LIBFT}
	@ ${MAKE} -C ${PATH_MLX}

${NAME}: ${OBJS} ${PATH_MLX}/${MLX} ${PATH_LIBFT}/libft.a
	@ echo "\n${_LIGHTRED}${_BOLD}${_DIM}$?${_END}\n" \
		"\t ${_YELLOW}${_DIM}${_BOLD}Add to ${NAME}!${_END} \n"
	@ ln -fs ${PATH_MLX}/${MLX} .
	@ ${CC} ${RENAME} ${CFLAGS} ${OBJS} ${LIBS}

# === Clean === #

clean:	
	@echo "${_LIGHTRED}${_DIM}.o files clean!${_END}"
	@ ${RM} ./${MLX}
	@ ${MAKE} clean -C ${PATH_LIBFT}
	@ ${MAKE} clean -C ${PATH_MLX}
	@ ${RM} ${PATH_OBJS}

fclean :	clean
	@ echo "${_LIGHTRED}${_DIM}${NAME} clean!${_END}"
	@ ${MAKE} fclean -C ${PATH_LIBFT}
	@ ${RM} ${NAME}

re :	fclean all

.PHONY :	all clean fclean re
