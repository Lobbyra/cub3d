# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Lobbyra <Lobbyra@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 09:12:12 by Lobbyra           #+#    #+#              #
#    Updated: 2020/07/09 13:44:19 by jecaudal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

SRCS		=	srcs/cub_exit.c						\
				srcs/cub_side_hited.c				\
				srcs/draw_background.c				\
				srcs/draw_sprites_utils.c			\
				srcs/draw_sprites.c					\
				srcs/draw_vert_line.c				\
				srcs/draw_vert_line_text.c			\
				srcs/free_stock.c					\
				srcs/panic_init_stock.c				\
				srcs/init_stock.c					\
				srcs/init_stock_utils.c				\
				srcs/init_stock_sprites.c			\
				srcs/init_stock_checkers.c			\
				srcs/key.c							\
				srcs/lmlx.c							\
				srcs/main.c							\
				srcs/save_bmp.c						\
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

MLX			=	-Lmlx -lmlx -framework OpenGL -framework AppKit

LIB			=	-Llibc_lobb/ -lclobb

all			:	$(NAME)

make_l_lib	:
				@make -C libc_lobb/

$(NAME)		:	make_l_lib $(OBJS)
				$(CC) -o $(NAME) $(MLX) $(LIB) $(OBJS)

play		:	$(NAME)
				./cub3d test_files/parsing_example_files/18_correct_squarre.cub

turbo		:	clean $(OBJS)
				$(CC) -o $(NAME) -O3 $(MLX) $(LIB) $(OBJS)

sanitize	:	$(OBJS)
				$(CC) -o $(NAME) -fsanitize=address $(MLX) $(LIB) $(OBJS)

clean		:
				rm -f $(OBJS)
				@make fclean -C libc_lobb

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all
