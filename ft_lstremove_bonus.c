/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melrose <melrose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 05:24:14 by aguiri            #+#    #+#             */
/*   Updated: 2025/04/28 19:55:18 by melrose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove(t_list **lst, t_list *elem_to_rm, void (*del)(void*))
{
	t_list	*prev;
	t_list	*current;

	prev = NULL;
	if (!lst || !*lst || !elem_to_rm)
		return ;
	current = *lst;
	while (current)
	{
		if (current == elem_to_rm)
		{
			if (!prev)
				*lst = current->next;
			else
				prev->next = current->next;
			ft_lstdelone(current, del);
			return ;
		}
		prev = current;
		current = current->next;
	}
}
