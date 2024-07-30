/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:18:46 by tbartocc          #+#    #+#             */
/*   Updated: 2024/07/14 19:19:29 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void error(void)
{
	write(2, "Error\n", 6);
	exit(84);
}

void parsing(int ac, char **av, list_t *list)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (av[ac - ++i])
	{
		j = -1;
		while (av[ac - ++i][++j])
		{
			if (j == 0)
				if (!ft_isdigit(av[ac - ++i][j]) && av[ac - ++i][j] != '-')
					error();
			else if (!ft_isdigit(av[ac - ++i][j]))
				error();
		}
	}
}

int	main(int ac, char **av)
{
	list_t	list;

	if (ac == 1)
		return (0);
	else
		parsing(ac, av, &list);
	//
	return (0);
}