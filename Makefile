# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 16:20:22 by ayarab            #+#    #+#              #
#    Updated: 2025/02/04 14:58:34 by wdaoudi-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/
SRC_BONUS = src_bonus/
OBJ = objs/
OBJ_BONUS = objs_bonus/
CFLAGS = -Wall -Wextra -Werror -g3

SRCS = $(addprefix $(SRC), main.c parsing/ft_parsing.c parsing/ft_check_asset.c parsing/ft_add_info.c parsing/ft_add_map.c parsing/ft_fill_color.c \
       data/init_data.c mlx/init_screen.c mlx/draw.c raycasting/raycasting.c event/player_handle.c mlx/draw_line.c \
	   utils/utils1.c )
	   
SRCS_BONUS =  $(addprefix $(SRC_BONUS), main.c parsing/ft_parsing.c parsing/ft_check_asset.c parsing/ft_add_info.c parsing/ft_add_map.c parsing/ft_fill_color.c \
       data/init_data.c mlx/init_screen.c mlx/draw.c raycasting/raycasting.c event/player_handle.c mlx/draw_line.c \
	   utils/utils1.c )

OBJS = $(SRCS:$(SRC)%.c=$(OBJ)%.o)
OBJS_BONUS = $(SRCS_BONUS:$(SRC_BONUS)%.c=$(OBJ_BONUS)%.o)

INCLUDES = -I ./include -I ./libft
LIBFT = libft.a
LIB_DIR = ./libft
MINI_LIBX_DIR = ./minilibx-linux
MINI_LIBX = libmlx.a
NAME = cub3D
BONUS = cub3D_bonus

all: $(NAME)

$(NAME): $(LIBFT) $(MINI_LIBX) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(INCLUDES) -L$(LIB_DIR) -lft -L$(MINI_LIBX_DIR) -lmlx -lX11 -lXext -lm -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(LIBFT) $(MINI_LIBX) $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) $(CFLAGS) $(INCLUDES) -L$(LIB_DIR) -lft -L$(MINI_LIBX_DIR) -lmlx -lX11 -lXext -lm -o $(BONUS)

$(LIBFT):
	make -C $(LIB_DIR)

$(MINI_LIBX):
	make -C $(MINI_LIBX_DIR)

$(OBJ)%.o: $(SRC)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_BONUS)%.o: $(SRC_BONUS)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


clean:
	rm -rf $(OBJ) $(OBJ_BONUS)
	make clean -C $(LIB_DIR)
	make clean -C $(MINI_LIBX_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS)
	make fclean -C $(LIB_DIR)

re: fclean all

.PHONY: all clean fclean re