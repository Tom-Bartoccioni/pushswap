/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:30:01 by tbartocc          #+#    #+#             */
/*   Updated: 2024/08/26 14:17:52 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

int	is_sorted(t_lst *lst_a)
{
	while (lst_a && lst_a->next)
	{
		if (lst_a->number > lst_a->next->number)
			return (0);
		lst_a = lst_a->next;
	}
	return (1);
}

void	sort_three(t_lst **lst_a, t_lst **lst_b)
{
	int	first;
	int	second;
	int	third;

	first = (*lst_a)->number;
	second = (*lst_a)->next->number;
	third = (*lst_a)->next->next->number;
	if (first < second && second < third)
		return ;
	else if (first < third && third < second)
	{
		op("sa", lst_a, lst_b);
		op("ra", lst_a, lst_b);
	}
	else if (second < first && first < third)
		op("sa", lst_a, lst_b);
	else if (second < third && third < first)
		op("rra", lst_a, lst_b);
	else if (third < first && first < second)
		op("ra", lst_a, lst_b);
	else if (third < second && second < first)
	{
		op("ra", lst_a, lst_b);
		op("sa", lst_a, lst_b);
	}
}

void	push_smallest(t_lst **lst_a, t_lst **lst_b)
{
	t_lst	*tmp;
	int		min;
	int		index;
	int		i;

	tmp = *lst_a;
	min = tmp->number;
	index = 0;
	i = -1;
	while (tmp && ++i >= -1)
	{
		if (tmp->number < min)
		{
			min = tmp->number;
			index = i;
		}
		tmp = tmp->next;
	}
	if (index <= ft_lst_size(*lst_a) / 2)
		while (index-- > 0)
			op("ra", lst_a, lst_b);
	else
		while (index++ < ft_lst_size(*lst_a))
			op("rra", lst_a, lst_b);
	op("pb", lst_a, lst_b);
}

void	sort_five(t_lst **lst_a, t_lst **lst_b)
{
	if (is_sorted(*lst_a))
		return ;
	push_smallest(lst_a, lst_b);
	push_smallest(lst_a, lst_b);
	sort_three(lst_a, lst_b);
	op("pa", lst_a, lst_b);
	op("pa", lst_a, lst_b);
}
