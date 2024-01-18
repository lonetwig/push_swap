/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:02:38 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/13 18:04:51 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	get_first_and_last_a(t_node *list_a, t_info *info)
{
	info->a_first = list_a->num;
	while (list_a->next)
		list_a = list_a->next;
	info->a_last = list_a->num;
}

static void	find_smallest(t_node *list_a, t_info *info)
{
	int	curr_small;
	int	curr_large;

	curr_small = list_a->num;
	curr_large = list_a->num;
	while (list_a)
	{
		if (list_a->num < curr_small)
			curr_small = list_a->num;
		if (list_a->num > curr_large)
			curr_large = list_a->num;
		list_a = list_a->next;
	}
	info->smallest_val = curr_small;
	info->largest_val = curr_large;
}

int	initialise_info(t_info **info, t_node *list_a)
{
	*info = malloc(sizeof(t_info));
	if (!(*info))
		return (1);
	get_first_and_last_a(list_a, *info);
	find_smallest(list_a, *info);
	return (0);
}
