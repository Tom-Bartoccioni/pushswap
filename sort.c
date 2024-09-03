/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:12:11 by tbartocc          #+#    #+#             */
/*   Updated: 2024/08/30 18:53:38 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

int	find_position_in_a(t_lst *element, t_lst *lst_a)
{
	t_lst	*current;
	int		cost;

	if (!lst_a)
		return (0);
	cost = 0;
	current = lst_a;
	if (element->number > find_max(lst_a)->number
		|| element->number < find_min(lst_a)->number)
		return (ft_lst_position(lst_a, find_max(lst_a)));
	while (current && current->next)
	{
		if (element->number < current->number
			&& element->number > current->next->number)
			return (cost + 1);
		cost++;
		current = current->next;
	}
	return (0);
}

int	find_position_in_b(t_lst *element, t_lst *lst_b)
{
	t_lst	*current;
	int		cost;

	if (!lst_b)
		return (0);
	cost = 0;
	current = lst_b;
	if (element->number > find_max(lst_b)->number
		|| element->number < find_min(lst_b)->number)
		return (ft_lst_position(lst_b, find_min(lst_b)));
	while (current && current->next)
	{
		if (element->number > current->number
			&& element->number < current->next->number)
			return (cost + 1);
		cost++;
		current = current->next;
	}
	return (0);
}
