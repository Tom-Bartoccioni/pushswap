/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:18:46 by tbartocc          #+#    #+#             */
/*   Updated: 2024/08/26 16:00:50 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"
#include <stdio.h>

void ft_print_list(t_lst *lst_a, t_lst *lst_b)
{
	printf("Stack A:\n");
	while (lst_a)
	{
		printf("Number: %d, ", lst_a->number);
		if (lst_a->prev)
			printf("Prev: %d, ", lst_a->prev->number);
		else
			printf("Prev: NULL, ");
		if (lst_a->next)
			printf("Next: %d\n", lst_a->next->number);
		else
			printf("Next: NULL\n");
		lst_a = lst_a->next;
	}
	printf("\n");
	printf("Stack B:\n");
	while (lst_b)
	{
		printf("Number: %d, ", lst_b->number);
		if (lst_b->prev)
			printf("Prev: %d, ", lst_b->prev->number);
		else
			printf("Prev: NULL, ");
		if (lst_b->next)
			printf("Next: %d\n", lst_b->next->number);
		else
			printf("Next: NULL\n");
		lst_b = lst_b->next;
	}
}


void	ft_free_tab_exit(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	error();
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

t_lst	*parsing(char **tab, int i, t_lst *lst_a)
{
	int	j;
	int	k;

	k = -1;
	while (tab[++k])
	{
		j = -1;
		while (tab[k][++j])
		{
			if (j == 0)
			{
				if (!ft_isdigit(tab[k][j]) && tab[k][j] != '-')
					ft_free_tab_exit(tab);
			}
			else if (!ft_isdigit(tab[k][j]))
				ft_free_tab_exit(tab);
			if (ft_atol(tab[k]) == (long) INT_MAX + 1)
				ft_free_tab_exit(tab);
		}
		if (is_duplicate(lst_a, ft_atoi(tab[k])))
			ft_free_tab_exit(tab);
		ft_lst_add_back(&lst_a, ft_lstnew_index(ft_atoi(tab[k]), i));
	}
	return (lst_a);
}

int	main(int ac, char **av)
{
	t_lst	*lst_a;
	t_lst	*lst_b;
	int		i;

	lst_a = NULL;
	lst_b = NULL;
	i = 0;
	while (++i < ac)
		lst_a = parsing(ft_split(av[i], ' '), i, lst_a);
	sort(lst_a, lst_b);
	return (0);
}
