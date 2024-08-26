/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:24:46 by tbartocc          #+#    #+#             */
/*   Updated: 2024/08/26 14:25:48 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src.h"

int	ft_lst_position(t_lst *lst, t_lst *element)
{
	int	position;

	position = 0;
	while (lst)
	{
		if (lst == element)
			return (position);
		position++;
		lst = lst->next;
	}
	return (-1);
}
