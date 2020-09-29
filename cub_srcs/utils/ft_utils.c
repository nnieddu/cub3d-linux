/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:17:53 by ninieddu          #+#    #+#             */
/*   Updated: 2020/09/29 11:25:56 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void		ft_catch_res(t_cub3d *game, char *line, int i)
{
	while ((line[i] < 48 || line[i] > 57) && line[i] != '\0')
		i++;
	if (line[i] != 32)
		game->width = ft_atoi(&line[i]);
	i += ft_size_t_len(game->width);
	while ((line[i] < 48 || line[i] > 57) && line[i] != '\0')
		i++;
	if (line[i] != 32 && line[i] != '\0')
		game->height = ft_atoi(&line[i]);
	i += ft_size_t_len(game->height);
	while (line[i])
	{
		if (line[i] != ' ')
			game->height = -1;
		i++;
	}
	if (game->width == -1 || game->height == -1)
	{
		ft_putstr("Error\nEmpty or bad resolution on arg R");
		ft_putstr(" (need to be less than int max)");
		ft_exit(game, 0);
	}
}

int			ft_check_number_next(char *line, int j)
{
	if (line[j] <= 48 || line[j] >= 57)
		j++;
	if (line[j] != '\0' && line[j] == ' ')
		while (line[j] != '\0' && line[j] == ' ')
			j++;
	return (j);
}

void		ft_check_number(t_cub3d *game, char *line, int j)
{
	while (line[j] != '\0')
	{
		j = ft_check_number_next(line, j);
		if (line[j] != '\0' && (line[j] <= 48 || line[j] >= 57))
		{
			while (line[j] != '\0' && (line[j] >= 48 && line[j] <= 57))
				j++;
			while (line[j] != '\0' && line[j] == ' ')
				j++;
			if (line[j] != '\0' && line[j] != ',')
			{
				ft_putstr("Error\nArgument F or C had a bad format.\n");
				ft_exit(game, 0);
			}
		}
		if (line[j] != '\0')
			j++;
	}
}

int			ft_is_map_ok(t_cub3d *game, int i, int n, int o)
{
	int		j;
	int		t;

	j = 0;
	t = 0;
	while (game->tmp_map[i])
	{
		if (game->tmp_map[i] == '\n')
			n++;
		if (game->tmp_map[i] == '1')
			o++;
		if (game->tmp_map[i] == '0')
			game->z++;
		if (game->tmp_map[i] == '\t')
			t++;
		i++;
	}
	if ((n < 2 || o < 4) && game->z == 0)
	{
		ft_putstr("Error\nMissings arg or empty / new line.\n");
		ft_exit(game, 0);
	}
	return (t);
}

char		*ft_strdup_texture(char *s1)
{
	size_t	i;
	size_t	len;
	char	*dup;

	len = 0;
	while (s1[len] && s1[len] != ' ')
		len++;
	if (!(dup = ft_calloc(sizeof(char), (len + 1))))
		return (dup);
	i = 0;
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	return (dup);
}
