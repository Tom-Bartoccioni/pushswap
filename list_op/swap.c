/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:08:59 by tbartocc          #+#    #+#             */
/*   Updated: 2024/08/29 16:37:17 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src.h"

void	sa(t_lst **lst)
{
	t_lst	*a;
	t_lst	*b;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	a = *lst;
	b = a->next;
	a->next = b->next;
	b->prev = a->prev;
	if (a->next)
		a->next->prev = a;
	b->next = a;
	a->prev = b;
	*lst = b;
}

void	sb(t_lst **lst)
{
	t_lst	*a;
	t_lst	*b;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	a = *lst;
	b = a->next;
	a->next = b->next;
	b->prev = a->prev;
	if (a->next)
		a->next->prev = a;
	b->next = a;
	a->prev = b;
	*lst = b;
}

void	ss(t_lst **lst_a, t_lst **lst_b)
{
	sa(lst_a);
	sb(lst_b);
}
