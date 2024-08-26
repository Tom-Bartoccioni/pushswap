/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:09:36 by tbartocc          #+#    #+#             */
/*   Updated: 2024/08/23 17:30:50 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src.h"

void	rra(t_lst **lst)
{
	t_lst	*last;
	t_lst	*second_last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	last = *lst;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *lst;
	(*lst)->prev = last;
	*lst = last;
}

void	rrb(t_lst **lst)
{
	t_lst	*last;
	t_lst	*second_last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	last = *lst;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *lst;
	(*lst)->prev = last;
	*lst = last;
}

void	rrr(t_lst **lst_a, t_lst **lst_b)
{
	rra(lst_a);
	rrb(lst_b);
}
