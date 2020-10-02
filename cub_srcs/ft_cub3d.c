/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 13:00:49 by ninieddu          #+#    #+#             */
/*   Updated: 2020/10/02 13:25:07 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void		ft_check_screen_size(t_cub3d *game)
{
	if (game->width_check < game->width)
	{
		game->width = game->width_check;
		ft_putstr("Error :\nmap width resized because ");
		ft_putstr("width is superior than the limit screen\n");
	}
	if (game->width < 400)
	{
		game->width = 400;
		ft_putstr("Error :\nmap width resized to 400 because ");
		ft_putstr("too small width\n");
	}
	if (game->height_check < game->height)
	{
		game->height = game->height_check;
		ft_putstr("Error :\nmap height resized because ");
		ft_putstr("height is superior than the limit screen\n");
	}
	if (game->height < 300)
	{
		game->height = 300;
		ft_putstr("Error :\nmap height resized to 300 because ");
		ft_putstr("too small height\n");
	}
}

void		ft_check_map_extension(t_cub3d *game)
{
	size_t	i;
	int		j;
	char	*check;

	check = ".cub";
	i = ft_strlen(game->map_path);
	j = 4;
	while (j != 0)
	{
		if (check[j] != game->map_path[i])
		{
			ft_putstr("Error\nMap extension need to be '.cub'\n");
			ft_exit(game, 0);
		}
		i--;
		j--;
	}
}

void		ft_check_args(t_cub3d *game, int ac, char **av)
{
	game->map_path = av[1];
	if (ac > 3)
	{
		ft_putstr("Error\nToo much arguments\n");
		ft_exit(game, 0);
	}
	if (ac < 2)
	{
		ft_putstr("Error\nToo few arguments (you need a map !)\n");
		ft_exit(game, 0);
	}
	if (ac == 3)
	{
		if (ft_strncmp(av[2], "--save", 6) == 0 && ft_strlen(av[2]) == 6)
			game->screenshot = 1;
		else
		{
			ft_putstr("Error\nBad argument, only '--save' allowed");
			ft_putstr("after the map path or bad map path (.cub needed).");
			ft_exit(game, 0);
		}
	}
	ft_check_map_extension(game);
}

int			main(int ac, char **av)
{
	t_cub3d		game[1];

	ft_init_game_struct(game);
	ft_check_args(game, ac, av);
	ft_map(game, 0, NULL);
	ft_view_init(game);
	if (!(game->mlx_ptr = mlx_init()))
		ft_exit(game, 1);
	mlx_get_screen_size(game->mlx_ptr, &game->width_check,
		&game->height_check);
	ft_check_screen_size(game);
	if (game->screenshot == 0)
		if (!(game->win_ptr = mlx_new_window(game->mlx_ptr, game->width,
			game->height, "Cub3D")))
			ft_exit(game, 1);
	game->tracked = 1;
	ft_texture_and_sprite_init(game);
	game->tracked = 8;
	if (!(game->zbuffer = malloc(sizeof(double) * game->width)))
		ft_exit(game, 1);
	ft_raycasting(game);
	mlx_loop_hook(game->mlx_ptr, ft_key_move, (void *)game);
	mlx_loop(game->mlx_ptr);
	ft_exit(game, 1);
	return (0);
}
