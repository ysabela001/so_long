# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 11:44:20 by ytavares          #+#    #+#              #
#    Updated: 2024/12/23 17:34:29 by ytavares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -g -Wall -Werror -Wextra
CC = cc 
MLX = libft/MLX42/build/libmlx42.a
MLX_FLAGS = -ldl -lglfw -pthread -lm -lXext

NAME = so_long

LIBFT = libft/lib/libft.a

SRCS = src/main.c\
	src/read_map.c\
	src/validate_map.c\
	src/copy_flood_free_map.c\
	src/graphic_manipulation.c\
	src/keyboard_events.c\
	src/get_next_line/get_next_line.c\
	src/get_next_line/get_next_line_utils.c\
	src/utils_for_game.c
	
OBJ = $(SRCS:%.c=%.o)

all: $(NAME)

./$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME) $(MLX_FLAGS)

$(LIBFT):
	make -C libft/lib

$(MLX):
	cmake  -S libft/MLX42 -B libft/MLX42/build
	cmake  -S libft/MLX42 --build libft/MLX42/build 
	make -C libft/MLX42/build
	
%.o: %.c
	$(CC) $(CFLAGS) -I include -I libft/lib -I libft/MLX42  -I src/get_next_line -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C libft/lib clean
	make -C libft/MLX42/build clean

fclean: clean
	rm -f $(NAME)
	make -C libft/lib fclean
	rm -rf libft/MLX42/build
	

re: fclean all

.PHONY: all clean fclean re

