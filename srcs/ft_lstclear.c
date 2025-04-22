/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melrose <melrose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:23:15 by aguiri            #+#    #+#             */
/*   Updated: 2025/04/22 00:07:53 by melrose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst_tmp;

	while (*lst != NULL)
	{
		lst_tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lst_tmp;
	}
}
