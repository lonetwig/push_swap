/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:02:44 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/15 09:46:42 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_node **list)
{
	t_node	*tmp;
	t_node	*sec_ele_tmp;

	if (!list || !(*list) || !(*list)->next)
		return ;
	tmp = *list;
	sec_ele_tmp = tmp->next;
	tmp->next = sec_ele_tmp->next;
	sec_ele_tmp->next = tmp;
	*list = sec_ele_tmp;
}

void	sa(t_node **list_a, t_info *info)
{
	my_print(1, "sa\n", 3);
	swap(list_a);
	info->a_first = (*list_a)->num;
}

void	sb(t_node **list_b, t_info *info)
{
	my_print(1, "sb\n", 3);
	swap(list_b);
	info->a_first = (*list_b)->num;
}

void	ss(t_node **list_a, t_node **list_b, t_info *info)
{
	my_print(1, "ss\n", 3);
	swap(list_a);
	swap(list_b);
	info->a_first = (*list_a)->num;
	info->b_first = (*list_b)->num;
}
