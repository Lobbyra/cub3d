# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Lobbyra <Lobbyra@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 09:12:12 by Lobbyra           #+#    #+#              #
#    Updated: 2020/01/06 15:55:58 by jecaudal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

SRCS		=

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		+=	-W -Wall -Wextra -Werror -ansi -pedantic -I libc_lobb/headers/

MLX			=	-L./mlx/ -lmlx

LIB			=	-L./libc_lobb/ -lc_lobb

mlx_build	:
				make -f ./mlx/Makefile

mlx_clean	:
				make -f ./mlx/Makefile clean

lib_build	:
				make -f ./libc_lobb/Makefile

lib_clean	:
				make -f ./libc_lobb/Makefile clean

all			:	$(NAME)

$(NAME)		:	mlx_build lib_build $(OBJS)
				$(CC) $(OBJS) $(MLX) $(LIB)

clean		:	mlx_clean lib_clean
				rm -f $(OBJS)

fclean		:	clean
				rm -f $(NAME)

re			:	clean fclean
