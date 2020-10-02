/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:38:42 by ninieddu          #+#    #+#             */
/*   Updated: 2020/09/30 13:18:40 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbr_words(char *str, char c)
{
	int		nbr;
	int		i;

	nbr = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] &&
				(str[i + 1] == c || str[i + 1] == '\0'))
		{
			i++;
			nbr++;
		}
		if (str[i] == '\0')
			return (nbr);
		i++;
	}
	return (nbr);
}

int		ft_len(char *str, int k, char c)
{
	int		len_word;

	len_word = 0;
	while (str[k] != c && str[k])
	{
		len_word++;
		k++;
	}
	return (len_word);
}

void	*ft_split_next(char *str, char **new, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (str[k])
	{
		while (str[k] == c && str[k])
			k++;
		if (str[k])
		{
			j = 0;
			if (!(new[i] = ft_calloc(sizeof(char), (ft_len(str, k, c) + 1))))
				return (NULL);
			while (str[k] != c && str[k])
				new[i][j++] = str[k++];
			i++;
		}
	}
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	char	*str;

	str = (char *)s;
	if (!str)
		return (NULL);
	if (!(new = ft_calloc(sizeof(char *), ft_nbr_words(str, c) + 1)))
		return (NULL);
	ft_split_next(str, new, c);
	return (new);
}
