/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:52:58 by ninieddu          #+#    #+#             */
/*   Updated: 2020/09/16 21:27:36 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	k = 0;
	if (size <= i)
	{
		j += size;
		return (j);
	}
	if (size >= i)
		j += i;
	while (src[k] && i + 1 < size)
		dst[i++] = src[k++];
	dst[i] = '\0';
	return (j);
}
