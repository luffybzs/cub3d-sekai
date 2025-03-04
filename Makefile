# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 16:20:22 by ayarab            #+#    #+#              #
#    Updated: 2025/03/04 15:39:22 by ayarab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/
SRC_BONUS = src_bonus/
OBJ_DIR = objs/
OBJ_BONUS_DIR = objs_bonus/
CFLAGS = -Wall -Wextra -Werror -g3

SRCS = $(addprefix $(SRC), main.c parsing/ft_parsing.c parsing/ft_check_asset.c parsing/ft_add_info.c parsing/ft_add_map.c parsing/ft_fill_color.c \
       data/init_data.c data/init_data2.c mlx/init_screen.c mlx/draw.c raycasting/raycasting.c event/player_handle.c event/player_handle2.c mlx/draw_line.c \
	   utils/utils1.c parsing/ft_utils_parsing.c parsing/ft_utils_parsing2.c parsing/ft_add_key.c)
	   
SRCS_BONUS =  $(addprefix $(SRC_BONUS), main.c parsing/ft_parsing.c parsing/ft_check_asset.c parsing/ft_add_info.c parsing/ft_add_map.c parsing/ft_fill_color.c \
       data/init_data.c data/init_data2.c mlx/init_screen.c mlx/draw.c raycasting/raycasting.c raycasting/raycasting2.c event/player_handle.c event/player_handle2.c event/player_handle3.c \
	    mlx/draw_line.c utils/utils1.c mlx/minimap.c event/handle_door.c parsing/ft_parsing_utils.c parsing/ft_parsing_utils2.c parsing/ft_add_key.c)

OBJS = $(SRCS:$(SRC)%.c=$(OBJ_DIR)%.o)
OBJS_BONUS = $(SRCS_BONUS:$(SRC_BONUS)%.c=$(OBJ_BONUS_DIR)%.o)

INCLUDES = -I ./include -I ./libft
LIBFT = libft.a
LIB_DIR = ./libft
MINI_LIBX_DIR = ./minilibx-linux
MINI_LIBX = libmlx.a
NAME = cub3D
BONUS = cub3D_bonus

all: $(NAME)

#$(NAME): $(OBJS) $(LIBFT) $(MINI_LIBX)
#	$(CC) $(OBJS) $(CFLAGS) $(INCLUDES) -L$(LIB_DIR) -lft -L$(MINI_LIBX_DIR) -lmlx -lX11 -lXext -lm -o $(NAME)
$(NAME): $(OBJS) $(LIBFT) $(MINI_LIBX)
	@if [ ! -f $(NAME) ] || [ -n "$$(find $(OBJS) -newer $(NAME) 2>/dev/null)" ]; then \
		$(CC) $(OBJS) $(CFLAGS) $(INCLUDES) -L./libft -lft -L./minilibx-linux -lmlx -lX11 -lXext -lm -o $(NAME); \
	else \
		echo "$(NAME) is up to date"; \
	fi

bonus: $(BONUS)

#$(BONUS): $(OBJS_BONUS) $(LIBFT) $(MINI_LIBX) 
#	$(CC) $(OBJS_BONUS) $(CFLAGS) $(INCLUDES) -L$(LIB_DIR) -lft -L$(MINI_LIBX_DIR) -lmlx -lX11 -lXext -lm -o $(BONUS)
$(BONUS): $(OBJS_BONUS) $(LIBFT) $(MINI_LIBX)
	@if [ ! -f $(BONUS) ] || [ -n "$$(find $(OBJS_BONUS) -newer $(BONUS) 2>/dev/null)" ]; then \
		$(CC) $(OBJS_BONUS) $(CFLAGS) $(INCLUDES) -L./libft -lft -L./minilibx-linux -lmlx -lX11 -lXext -lm -o $(BONUS); \
	else \
		echo "$(BONUS) is up to date"; \
	fi

$(LIBFT):
	$(MAKE) -C $(LIB_DIR)

$(MINI_LIBX):
	$(MAKE) -C $(MINI_LIBX_DIR)

$(OBJ_DIR)%.o: $(SRC)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
#	@echo "Compiling: $<"

$(OBJ_BONUS_DIR)%.o: $(SRC_BONUS)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
#	@echo "Compiling bonus: $<"


clean:
#	@echo "Cleaning object files..."
	@rm -rf $(OBJ_DIR) 
	@rm -rf $(OBJ_BONUS_DIR)
	make clean -C $(LIB_DIR)
	make clean -C $(MINI_LIBX_DIR)

fclean: clean
#	 @echo "Cleaning executables..."
	rm -f $(NAME) $(BONUS)
	make fclean -C $(LIB_DIR)

re: fclean all

.PHONY: all clean fclean re bonus