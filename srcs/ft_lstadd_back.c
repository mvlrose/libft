/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melrose <melrose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:00:06 by aguiri            #+#    #+#             */
/*   Updated: 2025/04/22 00:07:53 by melrose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*lst_last;

	if (*alst == NULL)
		*alst = new;
	else
	{
		lst_last = ft_lstlast(*(alst));
		lst_last->next = new;
	}
}
