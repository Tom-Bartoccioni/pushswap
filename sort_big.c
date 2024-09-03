/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:30:12 by tbartocc          #+#    #+#             */
/*   Updated: 2024/09/02 12:38:34 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	execute_move(t_lst *cheapest, t_lst **lst_a, t_lst **lst_b, char stack)
{
	if (stack == 'a')
	{
		opti_rotate(cheapest, lst_a, lst_b);
		op("pb", lst_a, lst_b);
	}
	else if (stack == 'b')
	{
		opti_rotate(cheapest, lst_a, lst_b);
		op("pa", lst_a, lst_b);
	}
}

int	opti_calculate_cost(t_lst *lst_a, t_lst *lst_b, int cost_a, int cost_b)
{
	if (cost_a > ft_lst_size(lst_a) / 2 && cost_b > ft_lst_size(lst_b) / 2)
	{
		cost_a = ft_lst_size(lst_a) - cost_a;
		cost_b = ft_lst_size(lst_b) - cost_b;
		if (cost_a > cost_b)
			return (cost_a);
		else
			return (cost_b);
	}
	else if (cost_a <= ft_lst_size(lst_a) / 2
		&& cost_b <= ft_lst_size(lst_b) / 2)
	{
		if (cost_a > cost_b)
			return (cost_a);
		else
			return (cost_b);
	}
	else
	{
		if (cost_a > ft_lst_size(lst_a) / 2)
			cost_a = ft_lst_size(lst_a) - cost_a;
		if (cost_b > ft_lst_size(lst_b) / 2)
			cost_b = ft_lst_size(lst_b) - cost_b;
		return (cost_a + cost_b);
	}
}

int	calculate_cost(t_lst *current, t_lst *lst_a, t_lst *lst_b, char stack)
{
	int	cost_a;
	int	cost_b;
	int	total;

	if (stack == 'a')
	{
		cost_a = ft_lst_position(lst_a, current);
		cost_b = find_position_in_a(current, lst_b);
		total = opti_calculate_cost(lst_a, lst_b, cost_a, cost_b);
	}
	else
	{
		cost_b = ft_lst_position(lst_b, current);
		cost_a = find_position_in_b(current, lst_a);
		total = opti_calculate_cost(lst_a, lst_b, cost_a, cost_b);
	}
	return (total);
}

void	find_cheapest_move(t_lst **lst_a, t_lst **lst_b, char stack)
{
	t_lst	*cheapest;
	t_lst	*current;
	int		min_cost;
	int		total_cost;

	cheapest = *lst_a;
	current = *lst_a;
	if (stack == 'b')
	{
		cheapest = *lst_b;
		current = *lst_b;
	}
	min_cost = INT_MAX;
	while (current)
	{
		total_cost = calculate_cost(current, *lst_a, *lst_b, stack);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			cheapest = current;
		}
		current = current->next;
	}
	execute_move(cheapest, lst_a, lst_b, stack);
}

void	sort(t_lst **lst_a, t_lst **lst_b)
{
	int	size;

	size = ft_lst_size(*lst_a);
	if (size == 3)
		sort_three(lst_a, lst_b);
	else if (size == 4)
		sort_four(lst_a, lst_b);
	else if (size == 5)
		sort_five(lst_a, lst_b);
	else
	{
		op("pb", lst_a, lst_b);
		op("pb", lst_a, lst_b);
		if (ft_lst_size(*lst_a) == 4)
		{
			sort_four(lst_a, lst_b);
			return ;
		}
		while (*lst_a && ft_lst_size(*lst_a) > 5)
			find_cheapest_move(lst_a, lst_b, 'a');
		sort_five(lst_a, lst_b);
		rotate_to_top(lst_a, lst_b, 'b');
		push_back(lst_a, lst_b);
		rotate_to_top(lst_a, lst_b, 'a');
	}
}
