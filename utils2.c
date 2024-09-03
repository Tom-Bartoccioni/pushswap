/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:50:57 by tbartocc          #+#    #+#             */
/*   Updated: 2024/09/03 15:24:30 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	push_back(t_lst **lst_a, t_lst **lst_b)
{
	while (*lst_b)
	{
		rotation_a(lst_a, lst_b, find_position_in_b(*lst_b, *lst_a));
		op("pa", lst_a, lst_b);
	}
}

void	op(char *op, t_lst **lst_a, t_lst **lst_b)
{
	if (!ft_strcmp(op, "pa"))
		pa(lst_a, lst_b);
	if (!ft_strcmp(op, "pb"))
		pb(lst_a, lst_b);
	if (!ft_strcmp(op, "sa") || !ft_strcmp(op, "ss"))
		sa(lst_a);
	if (!ft_strcmp(op, "sb") || !ft_strcmp(op, "ss"))
		sb(lst_b);
	if (!ft_strcmp(op, "ra") || !ft_strcmp(op, "rr"))
		ra(lst_a);
	if (!ft_strcmp(op, "rb") || !ft_strcmp(op, "rr"))
		rb(lst_b);
	if (!ft_strcmp(op, "rra") || !ft_strcmp(op, "rrr"))
		rra(lst_a);
	if (!ft_strcmp(op, "rrb") || !ft_strcmp(op, "rrr"))
		rrb(lst_b);
	ft_putstr(op);
	ft_putchar('\n');
}

t_lst	*parsing(char **tab, t_lst *lst_a, int k)
{
	int	j;

	while (tab[++k])
	{
		j = -1;
		while (tab[k][++j])
		{
			if (j == 0)
			{
				if (!ft_isdigit(tab[k][j]) && tab[k][j] != '-'
					|| !ft_strcmp(tab[k], "-"))
					ft_free_tab_lst_exit(tab, lst_a);
			}
			else if (!ft_isdigit(tab[k][j]))
				ft_free_tab_lst_exit(tab, lst_a);
			if (ft_atol(tab[k]) == (long) INT_MAX + 1)
				ft_free_tab_lst_exit(tab, lst_a);
		}
		if (is_duplicate(lst_a, ft_atoi(tab[k])))
			ft_free_tab_lst_exit(tab, lst_a);
		ft_lst_add_back(&lst_a, ft_lst_new(ft_atoi(tab[k])));
	}
	ft_free_tab(tab);
	return (lst_a);
}

t_lst	*find_max(t_lst *lst)
{
	t_lst	*max_element;

	if (!lst)
		return (NULL);
	max_element = lst;
	while (lst)
	{
		if (lst->number > max_element->number)
			max_element = lst;
		lst = lst->next;
	}
	return (max_element);
}

t_lst	*find_min(t_lst *lst)
{
	t_lst	*min_element;

	if (!lst)
		return (NULL);
	min_element = lst;
	while (lst)
	{
		if (lst->number < min_element->number)
			min_element = lst;
		lst = lst->next;
	}
	return (min_element);
}
