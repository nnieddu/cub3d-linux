/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:55:56 by ninieddu          #+#    #+#             */
/*   Updated: 2020/09/07 16:54:37 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*dup;

	len = 0;
	while (s1[len])
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
