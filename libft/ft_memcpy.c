/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:04:33 by ninieddu          #+#    #+#             */
/*   Updated: 2020/09/07 16:53:43 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst2;
	const char	*src2;

	if (!dst && !src)
		return (dst);
	dst2 = (char *)dst;
	src2 = (const char *)src;
	while (n--)
		*dst2++ = *src2++;
	return (dst);
}
