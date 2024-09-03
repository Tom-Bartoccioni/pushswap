/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:50:44 by tbartocc          #+#    #+#             */
/*   Updated: 2024/09/02 12:38:55 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	is_same_rota(t_lst *cheap, t_lst **lst_a, t_lst **lst_b, t_rotate *rota)
{
	rota->cost_a = ft_lst_position(*lst_a, cheap);
	rota->cost_b = find_position_in_a(cheap, *lst_b);
	if (rota->cost_a <= ft_lst_size(*lst_a) / 2)
		rota->ra_or_rra = 0;
	else
	{
		rota->cost_a = ft_lst_size(*lst_a) - rota->cost_a;
		rota->ra_or_rra = 1;
	}
	if (rota->cost_b <= ft_lst_size(*lst_b) / 2)
		rota->rb_or_rrb = 0;
	else
	{
		rota->cost_b = ft_lst_size(*lst_b) - rota->cost_b;
		rota->rb_or_rrb = 1;
	}
}

void	is_rr(t_lst **lst_a, t_lst **lst_b, t_rotate *rotate)
{
	if (rotate->uncommon_cost >= 0)
	{
		while (rotate->cost_a-- - rotate->cost_b != 0)
			op("ra", lst_a, lst_b);
		while (rotate->cost_b-- != 0)
			op("rr", lst_a, lst_b);
	}
	else
	{
		while (rotate->cost_b-- - rotate->cost_a != 0)
			op("rb", lst_a, lst_b);
		while (rotate->cost_a-- != 0)
			op("rr", lst_a, lst_b);
	}
}

void	is_rrr(t_lst **lst_a, t_lst **lst_b, t_rotate *rotate)
{
	if (rotate->uncommon_cost >= 0)
	{
		while (rotate->cost_a-- - rotate->cost_b != 0)
			op("rra", lst_a, lst_b);
		while (rotate->cost_b-- != 0)
			op("rrr", lst_a, lst_b);
	}
	else
	{
		while (rotate->cost_b-- - rotate->cost_a != 0)
			op("rrb", lst_a, lst_b);
		while (rotate->cost_a-- != 0)
			op("rrr", lst_a, lst_b);
	}
}

void	opti_rotate(t_lst *cheapest, t_lst **lst_a, t_lst **lst_b)
{
	t_rotate	*rotate;

	rotate = (t_rotate *)malloc(sizeof(t_rotate));
	is_same_rota(cheapest, lst_a, lst_b, rotate);
	if (rotate->ra_or_rra == rotate->rb_or_rrb)
	{
		rotate->uncommon_cost = rotate->cost_a - rotate->cost_b;
		if (rotate->ra_or_rra == 0)
			is_rr(lst_a, lst_b, rotate);
		else
			is_rrr(lst_a, lst_b, rotate);
	}
	else
	{
		rotation_a(lst_a, lst_b, ft_lst_position(*lst_a, cheapest));
		rotation_b(lst_a, lst_b, find_position_in_a(cheapest, *lst_b));
	}
	free(rotate);
}
