# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/28 11:37:56 by ninieddu          #+#    #+#              #
#    Updated: 2020/09/28 20:49:23 by ninieddu         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS =	cub_srcs/ft_cub3d.c\
		cub_srcs/ft_screenshot.c\
		cub_srcs/ft_exit.c\
		cub_srcs/ft_utils.c\
		cub_srcs/init/ft_struct_and_textures_init.c\
		cub_srcs/init/ft_fov_init.c\
		cub_srcs/map_ft/ft_read_and_check_map.c\
		cub_srcs/map_ft/ft_check_map.c\
		cub_srcs/map_ft/ft_check_map_next.c\
		cub_srcs/map_ft/ft_check_map_arg.c\
		cub_srcs/map_ft/ft_texture_path.c\
		cub_srcs/map_ft/ft_f_and_c_colors.c\
		cub_srcs/calc_and_raycast/ft_raycasting.c\
		cub_srcs/calc_and_raycast/ft_key_input.c\
		cub_srcs/calc_and_raycast/ft_texture.c\
		cub_srcs/calc_and_raycast/ft_draw.c\
		cub_srcs/calc_and_raycast/ft_sprite.c\
		cub_srcs/calc_and_raycast/ft_move_see.c\

SRCS_BONUS =	cub_srcs/ft_cub3d.c\
				cub_srcs/ft_screenshot.c\
				cub_srcs/ft_exit.c\
				cub_srcs/ft_utils.c\
				cub_srcs/init/ft_struct_and_textures_init.c\
				cub_srcs/init/ft_fov_init.c\
				cub_srcs/map_ft/ft_read_and_check_map.c\
				cub_srcs/map_ft/ft_check_map.c\
				cub_srcs/map_ft/ft_check_map_next.c\
				cub_srcs/map_ft/ft_check_map_arg.c\
				cub_srcs/map_ft/ft_texture_path.c\
				cub_srcs/map_ft/ft_f_and_c_colors.c\
				cub_srcs/calc_and_raycast/ft_raycasting.c\
				cub_srcs/calc_and_raycast/ft_key_input.c\
				cub_srcs/calc_and_raycast/ft_texture.c\
				cub_srcs/calc_and_raycast/ft_draw.c\
				cub_srcs/calc_and_raycast/ft_sprite.c\
				cub_srcs/bonus/ft_win_bonus.c\
				cub_srcs/bonus/ft_move_see_bonus.c\

LIBFT_PATH =	./libft
MLX_PATH =	./minilibx-linux
HEADERS =	./cub_srcs/ft_cub3d.h
OBJS =	$(SRCS:.c=.o)
OBJS_BONUS =	$(SRCS_BONUS:.c=.o)
NAME =	Cub3D
BONUS = Cub3D_BONUS
CC =	clang
CFLAGS =	-Wall -Wextra -Werror
FLAGS =		-lX11 -lXext -lm
RM =	rm -f

all :		${NAME}

$(NAME) :	$(OBJS) ${HEADERS}
			$(MAKE) -C $(LIBFT_PATH) all
			$(MAKE) -C $(MLX_PATH) all
			$(CC) $(CFLAGS) -o ${NAME} $(OBJS) ./libft/libft.a ./minilibx-linux/libmlx.a $(FLAGS)

clean :		
			$(MAKE) -C $(LIBFT_PATH) clean
			$(MAKE) -C $(MLX_PATH) clean
			$(RM) $(OBJS) $(OBJS_BONUS) ./screenshot.bmp

fclean 	:	clean
			$(MAKE) -C $(LIBFT_PATH) fclean
			$(RM) ${NAME} ${BONUS}

re :		fclean all

bonus :		${BONUS}
			@echo "\n/!\ [Please use 800*600 resolution to play bonus.] /!\ \n"

$(BONUS) :	$(OBJS_BONUS) ${HEADERS}
			$(MAKE) -C $(LIBFT_PATH) all
			$(MAKE) -C $(MLX_PATH) all
			$(RM) ${NAME}
			$(CC) $(CFLAGS) -o ${BONUS} $(OBJS_BONUS) ./libft/libft.a ./minilibx-linux/libmlx.a $(FLAGS)

rebonus :	fclean bonus

.PHONY :	all clean fclean re bonus rebonus
