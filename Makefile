# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Lobbyra <Lobbyra@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 09:12:12 by Lobbyra           #+#    #+#              #
#    Updated: 2020/02/21 10:13:22 by jecaudal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

SRCS		=	srcs/cub_exit.c						\
				srcs/cub_side_hited.c				\
				srcs/debug/print_t_err.c			\
				srcs/debug/print_t_file.c			\
				srcs/debug/print_t_info.c			\
				srcs/debug/print_t_sig.c			\
				srcs/debug/print_t_stock.c			\
				srcs/draw_background.c				\
				srcs/draw_vert_line.c				\
				srcs/draw_vert_line_text.c			\
				srcs/free_stock.c					\
				srcs/init_stock.c					\
				srcs/init_stock_utils.c				\
				srcs/key.c							\
				srcs/lmlx.c							\
				srcs/main.c							\
				srcs/parsing/color_miner.c			\
				srcs/parsing/detect_line.c			\
				srcs/parsing/free_file.c			\
				srcs/parsing/free_info.c			\
				srcs/parsing/get_file.c				\
				srcs/parsing/get_info.c				\
				srcs/parsing/get_map.c				\
				srcs/parsing/init_file.c			\
				srcs/parsing/init_info.c			\
				srcs/parsing/is_map.c				\
				srcs/parsing/parsing.c				\
				srcs/parsing/parsing_color.c		\
				srcs/parsing/parsing_file.c			\
				srcs/parsing/parsing_map.c			\
				srcs/parsing/parsing_map_utils.c	\
				srcs/parsing/parsing_path.c			\
				srcs/parsing/parsing_resolution.c	\
				srcs/parsing/path_miner.c			\
				srcs/parsing/print_err_file.c		\
				srcs/parsing/resolution_miner.c		\
				srcs/perform_raycasting.c			\
				srcs/player_update.c				\
				srcs/raycasting.c					\
				srcs/render.c

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		+=	-W -Wall -Wextra -Werror -ansi -pedantic -I headers -I libc_lobb/headers/

MLX			=	-lmlx -framework OpenGL -framework AppKit

LIB			=	-Llibc_lobb/ -lclobb

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(MLX) $(LIB) $(OBJS)

turbo		:	clean $(OBJS)
				$(CC) -O3 $(MLX) $(LIB) $(OBJS)

clean		:
				rm -f $(OBJS)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all
