/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:13:10 by tbartocc          #+#    #+#             */
/*   Updated: 2024/08/20 17:07:20 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src.h"

t_lst	*ft_lstnew_index(int number, int i)
{
	t_lst	*new_element;

	new_element = (t_lst *)malloc(sizeof(t_lst));
	if (!new_element)
		return (NULL);
	new_element->number = number;
	new_element->index = i;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}
