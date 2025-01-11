# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 16:20:22 by ayarab            #+#    #+#              #
#    Updated: 2025/01/11 16:06:36 by wdaoudi-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

SRCS = $(addprefix src/, main.c ./raycasting/init_data.c ./raycasting/init_screen.c )

INCLUDES = -I ./include -I ./libft

LIBFT = libft.a
LIB_DIR = ./libft
MINI_LIBX_DIR = ./minilibx-linux
MINI_LIBX = libmlx.a
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3

NAME = cube3d

all: $(MINI_LIBX) $(LIBFT) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIB_DIR)

$(MINI_LIBX):
	make -C $(MINI_LIBX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) -L$(LIB_DIR) -lft -L$(MINI_LIBX_DIR) -lmlx -lX11 -lXext

clean:
	rm -f $(OBJS)
	make clean -C $(LIB_DIR)
	make clean -C $(MINI_LIBX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
