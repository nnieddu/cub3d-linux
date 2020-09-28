/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:43:43 by ninieddu          #+#    #+#             */
/*   Updated: 2020/09/23 17:31:29 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void		ft_texture_no(t_cub3d *game)
{
	if (game->side == 1)
		game->wallx = game->posy + game->perspwalldist * game->raydiry;
	else
		game->wallx = game->posx + game->perspwalldist * game->raydirx;
	game->wallx -= floor((game->wallx));
	game->tex_x = (game->wallx * (double)game->no_width);
	if (game->side == 0 && game->raydiry > 0)
		game->tex_x = game->no_width - game->tex_x - 1;
	if (game->side == 1 && game->raydirx < 0)
		game->tex_x = game->no_width - game->tex_x - 1;
	game->step = 1.0 * game->no_height / game->lineheight;
	game->texpos = (game->drawstart - game->height / 2 + game->lineheight / 2)
	* game->step;
}

void		ft_texture_so(t_cub3d *game)
{
	if (game->side == 1)
		game->wallx = game->posy + game->perspwalldist * game->raydiry;
	else
		game->wallx = game->posx + game->perspwalldist * game->raydirx;
	game->wallx -= floor((game->wallx));
	game->tex_x = (game->wallx * (double)game->so_width);
	if (game->side == 0 && game->raydiry > 0)
		game->tex_x = game->so_width - game->tex_x - 1;
	if (game->side == 1 && game->raydirx < 0)
		game->tex_x = game->so_width - game->tex_x - 1;
	game->step = 1.0 * game->so_height / game->lineheight;
	game->texpos = (game->drawstart - game->height / 2 + game->lineheight / 2)
	* game->step;
}

void		ft_texture_we(t_cub3d *game)
{
	if (game->side == 1)
		game->wallx = game->posy + game->perspwalldist * game->raydiry;
	else
		game->wallx = game->posx + game->perspwalldist * game->raydirx;
	game->wallx -= floor((game->wallx));
	game->tex_x = (game->wallx * (double)game->we_width);
	if (game->side == 0 && game->raydiry > 0)
		game->tex_x = game->we_width - game->tex_x - 1;
	if (game->side == 1 && game->raydirx < 0)
		game->tex_x = game->we_width - game->tex_x - 1;
	game->step = 1.0 * game->we_height / game->lineheight;
	game->texpos = (game->drawstart - game->height / 2 + game->lineheight / 2)
	* game->step;
}

void		ft_texture_ea(t_cub3d *game)
{
	if (game->side == 1)
		game->wallx = game->posy + game->perspwalldist * game->raydiry;
	else
		game->wallx = game->posx + game->perspwalldist * game->raydirx;
	game->wallx -= floor((game->wallx));
	game->tex_x = (game->wallx * (double)game->ea_width);
	if (game->side == 0 && game->raydiry > 0)
		game->tex_x = game->ea_width - game->tex_x - 1;
	if (game->side == 1 && game->raydirx < 0)
		game->tex_x = game->ea_width - game->tex_x - 1;
	game->step = 1.0 * game->ea_height / game->lineheight;
	game->texpos = (game->drawstart - game->height / 2 + game->lineheight / 2)
	* game->step;
}

void		ft_texture(t_cub3d *game)
{
	if (game->side == 1 && game->stepx < 0)
		ft_texture_ea(game);
	if (game->side == 1 && game->stepx >= 0)
		ft_texture_we(game);
	if (game->side == 0 && game->stepy <= 0)
		ft_texture_so(game);
	if (game->side == 0 && game->stepy > 0)
		ft_texture_no(game);
}
