/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:37:06 by ninieddu          #+#    #+#             */
/*   Updated: 2020/09/07 16:55:42 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_set(char c, const char *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		i;
	int		i2;
	int		end_i;

	if (!s1 || !set)
		return (NULL);
	end_i = ft_strlen(s1) - 1;
	i = 0;
	i2 = 0;
	while (is_set(s1[i], set) != 0)
		i++;
	while (end_i >= i && is_set(s1[end_i], set) != 0)
		end_i--;
	if (end_i < i)
		return (ft_calloc(sizeof(char), 1));
	if (!(trim = ft_calloc(sizeof(char), (end_i - i + 2))))
		return (NULL);
	while (i <= end_i)
	{
		trim[i2] = s1[i];
		i2++;
		i++;
	}
	return (trim);
}
