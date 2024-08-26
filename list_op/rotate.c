/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:09:42 by tbartocc          #+#    #+#             */
/*   Updated: 2024/08/26 14:17:25 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src.h"

void	ra(t_lst **lst)
{
	t_lst	*first;
	t_lst	*last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	first = *lst;
	last = ft_lst_last(*lst);
	*lst = first->next;
	(*lst)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	rb(t_lst **lst)
{
	t_lst	*first;
	t_lst	*last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	first = *lst;
	last = ft_lst_last(*lst);
	*lst = first->next;
	(*lst)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	rr(t_lst **lst_a, t_lst **lst_b)
{
	ra(lst_a);
	rb(lst_b);
}
