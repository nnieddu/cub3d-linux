# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/28 11:37:56 by ninieddu          #+#    #+#              #
#    Updated: 2020/09/25 17:40:52 by ninieddu         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


SRC =	cub/ft_cub3d.c\
		cub/ft_screenshot.c\
		cub/ft_exit.c\
		cub/ft_utils.c\
		cub/init/ft_struct_and_textures_init.c\
		cub/init/ft_fov_init.c\
		cub/map_ft/ft_read_and_check_map.c\
		cub/map_ft/ft_check_map.c\
		cub/map_ft/ft_check_map_next.c\
		cub/map_ft/ft_check_map_arg.c\
		cub/map_ft/ft_texture_path.c\
		cub/map_ft/ft_f_and_c_colors.c\
		cub/calc_and_raycast/ft_raycasting.c\
		cub/calc_and_raycast/ft_key_input.c\
		cub/calc_and_raycast/ft_texture.c\
		cub/calc_and_raycast/ft_draw.c\
		cub/calc_and_raycast/ft_sprite.c\
		cub/calc_and_raycast/ft_move_see.c\

SRC_BONUS =	cub/ft_cub3d.c\
			cub/ft_screenshot.c\
			cub/ft_exit.c\
			cub/ft_utils.c\
			cub/init/ft_struct_and_textures_init.c\
			cub/init/ft_fov_init.c\
			cub/map_ft/ft_read_and_check_map.c\
			cub/map_ft/ft_check_map.c\
			cub/map_ft/ft_check_map_next.c\
			cub/map_ft/ft_check_map_arg.c\
			cub/map_ft/ft_texture_path.c\
			cub/map_ft/ft_f_and_c_colors.c\
			cub/calc_and_raycast/ft_raycasting.c\
			cub/calc_and_raycast/ft_key_input.c\
			cub/calc_and_raycast/ft_texture.c\
			cub/calc_and_raycast/ft_draw.c\
			cub/calc_and_raycast/ft_sprite.c\
			cub/bonus/ft_win_bonus.c\
			cub/bonus/ft_move_see_bonus.c\

LIBFT_PATH =	./libft
MINILIBX_PATH =	./minilibx-linux
HEADERS =		./cub/ft_cub3d.h
OBJ =	$(SRC:.c=.o) libft/libft.a minilibx-linux/libmlx.a
OBJ_BONUS =	$(SRC_BONUS:.c=.o) libft/libft.a minilibx-linux/libmlx.a
NAME =	Cub3D
NAME_BONUS = Cub3D_BONUS
CC =	clang
CFLAGS =	-Wall -Wextra -Werror
MLXFLAGS =	-lX11 -lXext -L minilibx-linux/ -lmlx -lm
RM =	rm -f

all :	libft_all minilibx_all ${NAME}

$(NAME) :	$(OBJ)
				$(CC) $(CFLAGS) -o $@ $(OBJ) $(MLXFLAGS)

%.o :	%.c $(HEADERS)
			@$(CC) $(CFLAGS) -o $@ -c $<

clean :		libft_clean minilibx_clean
				@$(RM) $(OBJ) $(OBJ_BONUS) ./screenshot.bmp

fclean 	:	clean libft_fclean
				@$(RM) ${NAME} ${NAME_BONUS}

re :	fclean all

bonus :	libft_all minilibx_all ${NAME_BONUS}

$(NAME_BONUS) :	$(OBJ_BONUS)
				$(CC) $(CFLAGS) -o $@ $(OBJ_BONUS) $(MLXFLAGS)


libft_all :
				make -C $(LIBFT_PATH) all


libft_clean :
				@make -C $(LIBFT_PATH) clean


libft_fclean :
				make -C $(LIBFT_PATH) fclean


minilibx_all :
				make -C $(MINILIBX_PATH) all


minilibx_clean :
				make -C $(MINILIBX_PATH) clean

.PHONY :	all bonus clean fclean re
