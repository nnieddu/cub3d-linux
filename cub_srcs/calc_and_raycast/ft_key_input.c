/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:19:29 by ninieddu          #+#    #+#             */
/*   Updated: 2020/09/17 09:14:40 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

int			ft_key_input(int key, t_cub3d *game)
{
	game->key = key;
	if (game->key == 65307)
	{
		ft_putstr("\nYou press ESC, good bye ! :)\n");
		ft_exit(game, 0);
	}
	if (game->key == 65361)
		game->left_arrow = 1;
	if (game->key == 65363)
		game->right_arrow = 1;
	if (game->key == 97)
		game->press_a = 1;
	if (game->key == 100)
		game->press_d = 1;
	if (game->key == 115)
		game->press_s = 1;
	if (game->key == 119)
		game->press_w = 1;
	if (game->key == 65505)
	{
		game->press_shift = 1;
		ft_putstr("\nVrouuuuum!\n");
	}
	return (1);
}

int			ft_key_release(int key, t_cub3d *game)
{
	game->key = key;
	if (game->key == 65361)
		game->left_arrow = 0;
	if (game->key == 65363)
		game->right_arrow = 0;
	if (game->key == 119)
		game->press_w = 0;
	if (game->key == 97)
		game->press_a = 0;
	if (game->key == 115)
		game->press_s = 0;
	if (game->key == 100)
		game->press_d = 0;
	if (game->key == 65505)
		game->press_shift = 0;
	return (1);
}
