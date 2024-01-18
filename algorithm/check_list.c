/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:42:04 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/16 13:24:45 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_list_length(t_node *list_a)
{
	int	i;

	i = 0;
	while (list_a)
	{
		list_a = list_a->next;
		i++;
	}
	return (i);
}

int	check_if_sorted(t_node *list_a)
{
	int	i;

	i = list_a->num;
	list_a = list_a->next;
	while (list_a)
	{
		if (list_a->num < i)
			return (0);
		i = list_a->num;
		list_a = list_a->next;
	}
	return (1);
}
