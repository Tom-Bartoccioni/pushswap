/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:53:46 by tbartocc          #+#    #+#             */
/*   Updated: 2024/09/02 19:17:46 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	op_checker(char *op, t_lst **lst_a, t_lst **lst_b)
{
	if (!op)
		return ;
	if (!ft_strcmp(op, "pa\n"))
		pa(lst_a, lst_b);
	if (!ft_strcmp(op, "pb\n"))
		pb(lst_a, lst_b);
	if (!ft_strcmp(op, "sa\n") || !ft_strcmp(op, "ss\n"))
		sa(lst_a);
	if (!ft_strcmp(op, "sb\n") || !ft_strcmp(op, "ss\n"))
		sb(lst_b);
	if (!ft_strcmp(op, "ra\n") || !ft_strcmp(op, "rr\n"))
		ra(lst_a);
	if (!ft_strcmp(op, "rb\n") || !ft_strcmp(op, "rr\n"))
		rb(lst_b);
	if (!ft_strcmp(op, "rra\n") || !ft_strcmp(op, "rrr\n"))
		rra(lst_a);
	if (!ft_strcmp(op, "rrb\n") || !ft_strcmp(op, "rrr\n"))
		rrb(lst_b);
}

int	parsing_checker(char *line)
{
	if (!line)
		return (1);
	return ((!ft_strcmp(line, "pa\n") || !ft_strcmp(line, "pb\n")
			|| !ft_strcmp(line, "ra\n") || !ft_strcmp(line, "rb\n")
			|| !ft_strcmp(line, "rra\n") || !ft_strcmp(line, "rrb\n")
			|| !ft_strcmp(line, "rr\n") || !ft_strcmp(line, "rrr\n")
			|| !ft_strcmp(line, "sa\n") || !ft_strcmp(line, "sb\n")
			|| !ft_strcmp(line, "ss\n")));
}

void	checker(t_lst **lst_a, t_lst **lst_b)
{
	char	*line;

	line = "";
	while (line != NULL)
	{
		line = get_next_line(0);
		if (!parsing_checker(line))
		{
			ft_free_lst(*lst_a);
			ft_free_lst(*lst_b);
			error();
		}
		op_checker(line, lst_a, lst_b);
		free(line);
	}
	if (is_sorted(*lst_a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
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
		lst_a = parsing(ft_split(av[i], ' '), lst_a);
	if (lst_a)
		checker(&lst_a, &lst_b);
	ft_free_lst(lst_a);
	ft_free_lst(lst_b);
	return (0);
}
