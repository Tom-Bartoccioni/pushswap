/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:18:46 by tbartocc          #+#    #+#             */
/*   Updated: 2024/09/02 17:35:03 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"
// #include <stdio.h>

// void	ft_print_list(t_lst *lst_a, t_lst *lst_b)
// {
// 	printf("Stack A:\n");
// 	while (lst_a)
// 	{
// 		printf("%d\n", lst_a->number);
// 		lst_a = lst_a->next;
// 	}
// 	printf("\n");
// 	printf("Stack B:\n");
// 	while (lst_b)
// 	{
// 		printf("%d\n", lst_b->number);
// 		lst_b = lst_b->next;
// 	}
// 	printf("\n");
// }

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
	sort(&lst_a, &lst_b);
	ft_free_lst(lst_a);
	ft_free_lst(lst_b);
	return (0);
}
