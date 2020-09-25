/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:04:00 by ninieddu          #+#    #+#             */
/*   Updated: 2020/09/07 17:01:15 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 1

#include "libft.h"

int		get_next_line(int fd, char **line)
{
	static char	*sv;
	char		*buffer;
	int			rret;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0
		|| (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	while (ft_lenline(sv) == -1
		&& (rret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[rret] = '\0';
		if (!(sv = ft_strjoin_gnl(sv, buffer)))
			return (-1);
	}
	buffer = ft_free(buffer);
	if (ft_lenline(sv) >= 0)
		return (next_gnl(&sv, line, &buffer));
	*line = ft_substr_gnl(sv, 0, ft_strlen_gnl(sv));
	sv = ft_free(sv);
	return (0);
}

int		next_gnl(char **sv, char **line, char **buffer)
{
	char	*buff_tmp;

	*line = ft_substr_gnl(*sv, 0, ft_lenline(*sv));
	buff_tmp = ft_substr_gnl(*sv, 0, ft_strlen_gnl(*sv));
	*buffer = *sv;
	*sv = ft_substr_gnl(buff_tmp, (ft_lenline(*sv) + 1), ft_strlen_gnl(*sv));
	*buffer = ft_free(*buffer);
	buff_tmp = ft_free(buff_tmp);
	return (1);
}
