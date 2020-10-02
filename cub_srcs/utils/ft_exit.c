/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 15:31:57 by ninieddu          #+#    #+#             */
/*   Updated: 2020/10/02 13:17:37 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void		ft_exit_end(t_cub3d *game)
{
	if (game->west != NULL)
		ft_memdel((void *)&(game->west));
	if (game->sprite != NULL)
		ft_memdel((void *)&(game->sprite));
	if (game->sp_order != NULL)
		ft_memdel((void *)&(game->sp_order));
	if (game->sp_order != NULL)
		ft_memdel((void *)&(game->sp_order));
	if (game->sp_dist != NULL)
		ft_memdel((void *)&(game->sp_dist));
	if (game->tracked > 7)
		ft_memdel((void *)&(game->zbuffer));
	if (game->mlx_ptr != NULL)
		ft_memdel((void*)&(game->mlx_ptr));
}

void		ft_exit_next(t_cub3d *game)
{
	int i;

	i = -1;
	if (game->map != NULL)
	{
		while (game->map[++i])
			ft_memdel((void*)&game->map[i]);
		ft_memdel((void*)&game->map);
	}
	if (game->tmp_map != NULL)
		ft_memdel((void*)&(game->tmp_map));
	if (game->south != NULL)
		ft_memdel((void *)&(game->south));
	if (game->north != NULL)
		ft_memdel((void *)&(game->north));
	if (game->east != NULL)
		ft_memdel((void *)&(game->east));
	ft_exit_end(game);
}

void		ft_exit_texture(t_cub3d *game)
{
	if (game->tracked > 0 && game->screenshot == 0)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->tracked > 1)
	{
		ft_putstr("Error\nIncorrect texture path or bad file.");
		mlx_destroy_image(game->mlx_ptr, game->img_ptr);
		if (game->tracked > 2 && game->img_no_ptr != 0)
			mlx_destroy_image(game->mlx_ptr, game->img_no_ptr);
		if (game->tracked > 3 && game->img_so_ptr != 0)
			mlx_destroy_image(game->mlx_ptr, game->img_so_ptr);
		if (game->tracked > 4 && game->img_ea_ptr != 0)
			mlx_destroy_image(game->mlx_ptr, game->img_ea_ptr);
		if (game->tracked > 5 && game->img_we_ptr != 0)
			mlx_destroy_image(game->mlx_ptr, game->img_we_ptr);
		if (game->tracked > 6 && game->sprite_ptr != 0)
			mlx_destroy_image(game->mlx_ptr, game->sprite_ptr);
	}
	ft_exit_next(game);
	exit(0);
}

int			ft_exit(t_cub3d *game, int x)
{
	if (x == 1)
		ft_putstr("Error\nMlx error or allocation error.\n");
	if (game->tracked > 0 && game->screenshot == 0)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->tracked > 1)
	{
		mlx_destroy_image(game->mlx_ptr, game->img_ptr);
		if (game->tracked > 2 && game->img_no_ptr != 0)
			mlx_destroy_image(game->mlx_ptr, game->img_no_ptr);
		if (game->tracked > 3 && game->img_so_ptr != 0)
			mlx_destroy_image(game->mlx_ptr, game->img_so_ptr);
		if (game->tracked > 4 && game->img_ea_ptr != 0)
			mlx_destroy_image(game->mlx_ptr, game->img_ea_ptr);
		if (game->tracked > 5 && game->img_we_ptr != 0)
			mlx_destroy_image(game->mlx_ptr, game->img_we_ptr);
		if (game->tracked > 6 && game->sprite_ptr != 0)
			mlx_destroy_image(game->mlx_ptr, game->sprite_ptr);
	}
	ft_exit_next(game);
	exit(0);
}
