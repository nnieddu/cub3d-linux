# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/28 11:37:56 by ninieddu          #+#    #+#              #
#    Updated: 2020/09/30 10:59:08 by ninieddu         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS =	cub_srcs/ft_cub3d.c\
		cub_srcs/utils/ft_screenshot.c\
		cub_srcs/utils/ft_exit.c\
		cub_srcs/utils/ft_utils.c\
		cub_srcs/init/ft_struct_and_textures_init.c\
		cub_srcs/init/ft_view_init.c\
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
		cub_srcs/calc_and_raycast/ft_move_see.c

SRCS_BONUS =	cub_srcs/ft_cub3d.c\
				cub_srcs/utils/ft_screenshot.c\
				cub_srcs/utils/ft_exit.c\
				cub_srcs/utils/ft_utils.c\
				cub_srcs/init/ft_struct_and_textures_init.c\
				cub_srcs/init/ft_view_init.c\
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
				cub_srcs/bonus/ft_move_see_bonus.c

LIBFT_PATH =	./libft
MLX_PATH =		./minilibx-linux
LIBS = 			./libft/libft.a ./minilibx-linux/libmlx.a
HEADER =		./cub_srcs/ft_cub3d.h

OBJS =		$(SRCS:.c=.o)
NAME =		Cub3D

BONUS =		Cub3D_BONUS
OBJS_B =	$(SRCS_BONUS:.c=.o)

CC =		clang
CFLAGS =	-Wall -Wextra -Werror
FLAGS =		-lX11 -lXext -lm
RM =		rm -f

all :		${NAME}

$(OBJS) :	$(HEADER)

$(NAME) :	$(OBJS)
			$(MAKE) -C $(LIBFT_PATH) all
			$(MAKE) -C $(MLX_PATH) all
			$(RM) ${BONUS}
			$(CC) $(CFLAGS) -o ${NAME} $(OBJS) ${LIBS} $(FLAGS)

clean :		
			$(MAKE) -C $(LIBFT_PATH) clean
			$(MAKE) -C $(MLX_PATH) clean
			$(RM) $(OBJS) $(OBJS_B) ./screenshot.bmp

fclean 	:	clean
			$(MAKE) -C $(LIBFT_PATH) fclean
			$(RM) ${NAME} ${BONUS}

re :		fclean all

bonus :		${BONUS}
			@echo "\n/!\ [Please use 800*600 resolution to play bonus.] /!\ \n"

$(OBJS_B) : $(HEADER)

$(BONUS) :	$(OBJS_B)
			$(MAKE) -C $(LIBFT_PATH) all
			$(MAKE) -C $(MLX_PATH) all
			$(RM) ${NAME}
			$(CC) $(CFLAGS) -o ${BONUS} $(OBJS_B) ${LIBS} $(FLAGS)

rebonus :	fclean bonus

.PHONY :	all clean fclean re bonus rebonus
