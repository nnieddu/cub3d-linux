/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:31:18 by ninieddu          #+#    #+#             */
/*   Updated: 2020/09/07 16:53:04 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nlst;

	nlst = *lst;
	while (nlst->next)
	{
		del(nlst);
		nlst = nlst->next;
		free(nlst);
	}
	del(nlst->next);
	free(nlst->next);
	*lst = NULL;
}
