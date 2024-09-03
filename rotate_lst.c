/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:51:25 by tbartocc          #+#    #+#             */
/*   Updated: 2024/08/30 18:51:06 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	rotation_a(t_lst **lst_a, t_lst **lst_b, int cost)
{
	if (cost == 0)
		return ;
	if (cost <= ft_lst_size(*lst_a) / 2)
		while (cost-- > 0)
			op("ra", lst_a, lst_b);
	else
	{
		cost = ft_lst_size(*lst_a) - cost;
		while (cost-- > 0)
			op("rra", lst_a, lst_b);
	}
}

void	rotation_b(t_lst **lst_a, t_lst **lst_b, int cost)
{
	if (cost == 0)
		return ;
	if (cost <= ft_lst_size(*lst_b) / 2)
		while (cost-- > 0)
			op("rb", lst_a, lst_b);
	else
	{
		cost = ft_lst_size(*lst_b) - cost;
		while (cost-- > 0)
			op("rrb", lst_a, lst_b);
	}
}

void	rotate_to_top(t_lst **lst_a, t_lst **lst_b, char stack)
{
	t_lst	*target_element;

	target_element = NULL;
	if (stack == 'a')
		rotation_a(lst_a, lst_b, ft_lst_position(*lst_a, find_min(*lst_a)));
	else if (stack == 'b')
		rotation_b(lst_a, lst_b, ft_lst_position(*lst_b, find_max(*lst_b)));
}
