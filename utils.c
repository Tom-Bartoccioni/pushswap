/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:13:58 by tbartocc          #+#    #+#             */
/*   Updated: 2024/09/02 14:04:53 by tbartocc         ###   ########.fr       */
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

void	ft_free_lst(t_lst *lst)
{
	t_lst	*tmp;

	while (lst && lst->next)
	{
		lst = lst->next;
		tmp = lst->prev;
		free(tmp);
	}
	free(lst);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	ft_free_tab_lst_exit(char **tab, t_lst *lst)
{
	ft_free_tab(tab);
	ft_free_lst(lst);
	error();
}
