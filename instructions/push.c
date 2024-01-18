/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:07:03 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/15 10:01:41 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	push(t_node **list_from, t_node **list_into)
{
	t_node	*node;
	t_node	*tmp;

	if (!list_from || !(*list_from))
		return (0);
	node = add_node((*list_from)->num);
	if (!node)
		return (1);
	node->next = *list_into;
	*list_into = node;
	tmp = *list_from;
	(*list_from) = (*list_from)->next;
	free(tmp);
	return (0);
}

void	pa(t_node **list_a, t_node **list_b, t_info *info)
{
	if (push(list_b, list_a) == 1)
	{
		my_print(2, "malloc failed.\n", 15);
		free_all(list_a, list_b, &info, NULL);
		exit(1);
	}
	info->a_first = (*list_a)->num;
	if (*list_b)
		info->b_first = (*list_b)->num;
	my_print(1, "pa\n", 3);
}

void	pb(t_node **list_a, t_node **list_b, t_info *info)
{
	if (push(list_a, list_b) == 1)
	{
		my_print(2, "malloc failed.\n", 15);
		free_all(list_a, list_b, &info, NULL);
		exit(1);
	}
	info->b_first = (*list_b)->num;
	if (*list_a)
		info->a_first = (*list_a)->num;
	my_print(1, "pb\n", 3);
}
