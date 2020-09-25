/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:53:36 by ninieddu          #+#    #+#             */
/*   Updated: 2020/09/07 21:02:32 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
	return (s);
}

char	*ft_substr_gnl(char *s, int start, int len)
{
	int		i;
	char	*new;

	i = 0;
	if (!s)
		s = NULL;
	if (ft_strlen_gnl(s) < start)
		len = 0;
	if (!(new = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len && s[start])
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*new;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_substr_gnl("", 0, 0);
	if (!(new = malloc(sizeof(char) *
		(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1))))
	{
		s1 = ft_free(s1);
		return (NULL);
	}
	while (s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new[j++] = s2[i++];
	new[j] = '\0';
	s1 = ft_free(s1);
	return (new);
}

int		ft_lenline(char *s)
{
	int		i;

	i = 0;
	if (s)
		while (s[i])
		{
			if (s[i] == '\n')
				return (i);
			i++;
		}
	return (-1);
}

int		ft_strlen_gnl(const char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
