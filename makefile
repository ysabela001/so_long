/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makefile                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:44:20 by ytavares          #+#    #+#             */
/*   Updated: 2024/11/29 13:05:56 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

CFLAGS	= -Wall -Werror -Wextra
CC		= cc $(CFLAGS)
MLX		= -lmlx -lXext -lX11

NAME =	so_long
LIBFT =	libft/libft.a
SRCS =	
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
	cd libft && $(MAKE)

%.o: %.c
	$(CC) -c $^

clean:
	rm -f $(OBJ)

fclean: clean
	cd libft && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re



/*NAME = so_long

CC = gcc
CFLAGS	= -Wall -Werror -Wextra

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
LIB_DIR = libs
MLX_DIR = $(LIB_DIR)/MLX42

SRCS = 

OBJ = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIB_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx42.a
MLX_FLAGS = -ldl -lglfw -pthread -lm

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(MLX_DIR)/include -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	cd $(LIB_DIR)/libft && $(MAKE)

clean:
	rm -f $(OBJ_DIR)
	cd $(LIB_DIR)/libft && $(MAKE) clean

fclean: clean
	cd $(LIB_DIR)/libft && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re/*
