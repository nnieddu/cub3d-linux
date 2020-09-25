/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:57:37 by ninieddu          #+#    #+#             */
/*   Updated: 2020/09/07 16:53:51 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dst2;
	const char	*src2;

	if (!dst && !src)
		return (dst);
	dst2 = (char *)dst;
	src2 = (const char *)src;
	i = 0;
	if (src2 < dst2)
		while (++i <= len)
			dst2[len - i] = src2[len - i];
	if (src2 > dst2)
		while (len--)
			*dst2++ = *src2++;
	return (dst);
}
