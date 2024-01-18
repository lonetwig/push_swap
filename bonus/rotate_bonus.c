/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 09:09:33 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/15 18:16:26 by ealislam         ###   ########.fr       */
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

void	ra_bonus(t_node **list_a, t_info *info)
{
	if (*list_a)
		info->a_last = (*list_a)->num;
	rotate(list_a);
	if (*list_a)
		info->a_first = (*list_a)->num;
}

void	rb_bonus(t_node **list_b, t_info *info)
{
	if (*list_b)
		info->b_last = (*list_b)->num;
	rotate(list_b);
	if (*list_b)
		info->b_first = (*list_b)->num;
}

void	rr_bonus(t_node **list_a, t_node **list_b, t_info *info)
{
	if (*list_a)
		info->a_last = (*list_a)->num;
	if (*list_b)
		info->b_last = (*list_b)->num;
	rotate(list_a);
	rotate(list_b);
	if (*list_a)
		info->a_first = (*list_a)->num;
	if (*list_b)
		info->b_first = (*list_b)->num;
}
