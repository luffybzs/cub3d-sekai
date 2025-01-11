/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:11:20 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/01/11 03:19:39 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*lstt;

	while (*lst)
	{
		lstt = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lstt;
	}
	free(*lst);
	*lst = NULL;
}
