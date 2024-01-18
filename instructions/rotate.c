/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 09:09:33 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/15 09:45:37 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_node **list)
{
	t_node	*tmp;
	t_node	*head;

	if (!list || !(*list) || !(*list)->next)
		return ;
	tmp = *list;
	head = *list;
	(*list) = (*list)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
	head->next = NULL;
}

void	ra(t_node **list_a, t_info *info)
{
	info->a_last = (*list_a)->num;
	my_print(1, "ra\n", 3);
	rotate(list_a);
	info->a_first = (*list_a)->num;
}

void	rb(t_node **list_b, t_info *info)
{
	info->b_last = (*list_b)->num;
	my_print(1, "rb\n", 3);
	rotate(list_b);
	info->b_first = (*list_b)->num;
}

void	rr(t_node **list_a, t_node **list_b, t_info *info)
{
	info->a_last = (*list_a)->num;
	info->b_last = (*list_b)->num;
	my_print(1, "ra\n", 3);
	rotate(list_a);
	rotate(list_b);
	info->a_first = (*list_a)->num;
	info->b_first = (*list_b)->num;
}
