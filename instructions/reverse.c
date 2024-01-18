/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 09:51:06 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/15 09:45:37 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_last(t_node *list)
{
	while (list->next)
		list = list->next;
	return (list->num);
}

static void	reverse(t_node **list)
{
	t_node	*pre_last;
	t_node	*new_head;

	if (!list || !(*list) || !(*list)->next)
		return ;
	pre_last = *list;
	while (pre_last->next->next)
		pre_last = pre_last->next;
	new_head = pre_last->next;
	pre_last->next = NULL;
	new_head->next = (*list);
	(*list) = new_head;
}

void	rra(t_node **list_a, t_info *info)
{
	info->a_first = info->a_last;
	my_print(1, "rra\n", 4);
	reverse(list_a);
	info->a_last = get_last(*list_a);
}

void	rrb(t_node **list_b, t_info *info)
{
	info->b_first = info->b_last;
	my_print(1, "rrb\n", 4);
	reverse(list_b);
	info->b_last = get_last(*list_b);
}

void	rrr(t_node **list_a, t_node **list_b, t_info *info)
{
	info->a_first = info->a_last;
	info->b_first = info->b_last;
	my_print(1, "rrr\n", 4);
	reverse(list_a);
	reverse(list_b);
	info->a_last = get_last(*list_a);
	info->b_last = get_last(*list_b);
}
