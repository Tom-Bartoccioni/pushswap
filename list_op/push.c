/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:09:09 by tbartocc          #+#    #+#             */
/*   Updated: 2024/08/23 17:30:35 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src.h"

void	pa(t_lst **a, t_lst **b)
{
	t_lst	*first_b;

	if (!b || !*b)
		return ;
	first_b = *b;
	*b = first_b->next;
	if (*b)
		(*b)->prev = NULL;
	first_b->next = *a;
	if (*a)
		(*a)->prev = first_b;
	*a = first_b;
	first_b->prev = NULL;
}

void	pb(t_lst **a, t_lst **b)
{
	t_lst	*first_a;

	if (!a || !*a)
		return ;
	first_a = *a;
	*a = first_a->next;
	if (*a)
		(*a)->prev = NULL;
	first_a->next = *b;
	if (*b)
		(*b)->prev = first_a;
	*b = first_a;
	first_a->prev = NULL;
}
