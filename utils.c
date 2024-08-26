/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:13:58 by tbartocc          #+#    #+#             */
/*   Updated: 2024/08/26 15:45:24 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(84);
}

int	is_duplicate(t_lst *lst, int number)
{
	while (lst)
	{
		if (lst->number == number)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	rotation_a(t_lst **lst_a, t_lst **lst_b, int cost_a)
{
	if (cost_a <= ft_lst_size(*lst_a) / 2)
		while (cost_a-- > 0)
			op("ra", lst_a, lst_b);
	else
	{
		cost_a = ft_lst_size(*lst_a) - cost_a;
		while (cost_a-- > 0)
			op("rra", lst_a, lst_b);
	}
}

void	rotation_b(t_lst **lst_a, t_lst **lst_b, int cost_b)
{
	if (cost_b <= ft_lst_size(*lst_b) / 2)
		while (cost_b-- > 0)
			op("rb", lst_a, lst_b);
	else
	{
		cost_b = ft_lst_size(*lst_b) - cost_b;
		while (cost_b-- > 0)
			op("rrb", lst_a, lst_b);
	}
}

int	find_position_in_second_lst(t_lst *element, t_lst *lst_b)
{
	int		position;
	t_lst	*current;

	position = 0;
	current = lst_b;
	if (!current)
		return (0);
	while (current && current->next)
	{
		if (element->number > current->number
			&& element->number < current->next->number)
			return (position);
		position++;
		current = current->next;
	}
	if (element->number > current->number)
	{
		return (position);
	}
	return (position);
}
