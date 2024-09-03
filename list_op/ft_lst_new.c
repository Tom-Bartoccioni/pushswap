/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:13:10 by tbartocc          #+#    #+#             */
/*   Updated: 2024/09/02 13:46:12 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src.h"

t_lst	*ft_lst_new(int number)
{
	t_lst	*new_element;

	new_element = (t_lst *)malloc(sizeof(t_lst));
	if (!new_element)
		return (NULL);
	new_element->number = number;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}
