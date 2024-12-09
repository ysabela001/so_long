/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makefile                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:44:20 by ytavares          #+#    #+#             */
/*   Updated: 2024/12/05 19:22:10 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

CFLAGS = -Wall -Werror -Wextra
CC = cc $(CFLAGS)
MLX = -lmlx -lXext -lX11

NAME = so_long
LIBFT = libft/libft.a
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

.PHONY: all clean fclean re

