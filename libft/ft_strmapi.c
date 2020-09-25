/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:40:11 by ninieddu          #+#    #+#             */
/*   Updated: 2020/09/07 16:55:23 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*nstr;
	size_t	i;

	i = 0;
	if (s && f)
	{
		if (!(nstr = ft_calloc(sizeof(char), (ft_strlen(s) + 1))))
			return (NULL);
		while (s[i])
		{
			nstr[i] = f(i, s[i]);
			i++;
		}
		return (nstr);
	}
	return (NULL);
}
