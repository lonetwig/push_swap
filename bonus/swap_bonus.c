/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:02:44 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/15 10:29:09 by ealislam         ###   ########.fr       */
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

void	sa_bonus(t_node **list_a, t_info *info)
{
	swap(list_a);
	info->a_first = (*list_a)->num;
}

void	sb_bonus(t_node **list_b, t_info *info)
{
	swap(list_b);
	info->a_first = (*list_b)->num;
}

void	ss_bonus(t_node **list_a, t_node **list_b, t_info *info)
{
	swap(list_a);
	swap(list_b);
	info->a_first = (*list_a)->num;
	info->b_first = (*list_b)->num;
}
