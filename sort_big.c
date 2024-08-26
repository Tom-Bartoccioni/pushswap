/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:30:12 by tbartocc          #+#    #+#             */
/*   Updated: 2024/08/26 15:51:58 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	execute_move(t_lst *cheapest, t_lst **lst_a, t_lst **lst_b, char stack)
{
	int	cost_a;
	int	cost_b;
	int	target_pos;

	cost_a = ft_lst_position(*lst_a, cheapest);
	rotation_a(lst_a, lst_b, cost_a);
	if (stack == 'a')
	{
		target_pos = find_position_in_second_lst(cheapest, *lst_b);
		cost_b = target_pos;
		rotation_b(lst_a, lst_b, cost_b);
		op("pb", lst_a, lst_b);
	}
	else if (stack == 'b')
	{
		target_pos = find_position_in_second_lst(cheapest, *lst_a);
		cost_b = target_pos;
		rotation_b(lst_a, lst_b, cost_b);
		op("pa", lst_a, lst_b);
	}
}

int	calculate_cost(t_lst *current, t_lst *lst_a, t_lst *lst_b)
{
	int	cost_a;
	int	cost_b;
	int	size_a;
	int	size_b;

	size_a = ft_lst_size(lst_a);
	size_b = ft_lst_size(lst_b);
	cost_a = ft_lst_position(lst_a, current);
	if (cost_a > size_a / 2)
		cost_a = size_a - cost_a;
	cost_b = find_position_in_second_lst(current, lst_b);
	if (cost_b > size_b / 2)
		cost_b = size_b - cost_b;
	return (cost_a + cost_b);
}

void	find_cheapest_move(t_lst *lst_a, t_lst *lst_b, char stack)
{
	t_lst	*cheapest;
	t_lst	*current;
	int		min_cost;
	int		total_cost;

	cheapest = lst_a;
	current = lst_a;
	if (stack == 'b')
	{
		cheapest = lst_b;
		current = lst_b;
	}
	min_cost = INT_MAX;
	while (current)
	{
		total_cost = calculate_cost(current, lst_a, lst_b);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			cheapest = current;
		}
		current = current->next;
	}
	execute_move(cheapest, &lst_a, &lst_b, stack);
}

void	sort(t_lst *lst_a, t_lst *lst_b)
{
	if (ft_lst_size(lst_a) == 3)
		sort_three(&lst_a, &lst_b);
	else if (ft_lst_size(lst_a) == 5)
		sort_five(&lst_a, &lst_b);
	else
	{
		op("pb", &lst_a, &lst_b);
		op("pb", &lst_a, &lst_b);
		while (ft_lst_size(lst_a) > 3)
		{
			find_cheapest_move(lst_a, lst_b, 'a');
		}
		sort_three(&lst_a, &lst_b);
		while (!is_sorted(lst_a))
		{
			find_cheapest_move(lst_a, lst_b, 'b');
		}
	}
	ft_print_list(lst_a, lst_b);
}
