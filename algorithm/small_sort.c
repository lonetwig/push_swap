/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:52:45 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/13 17:58:05 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	two_sort(t_node **list_a, t_info *info)
{
	if (info->a_first > info->a_last)
		sa(list_a, info);
}

void	three_sort(t_node **list_a, t_info *info)
{
	int	first;
	int	second;
	int	third;

	first = info->a_first;
	second = (*list_a)->next->num;
	third = info->a_last;
	if (first > second && first < third)
		sa(list_a, info);
	else if (first > second && second > third)
	{
		sa(list_a, info);
		rra(list_a, info);
	}
	else if (first > second && second < third)
		ra(list_a, info);
	else if (first < second && second > third && first < third)
	{
		rra(list_a, info);
		sa(list_a, info);
	}
	else if (first < second && second > third && first > third)
		rra(list_a, info);
}

static void	push_back2(t_node **list_a, t_node **list_b, t_info *info, int pos)
{
	if (pos == 1)
	{
		pa(list_a, list_b, info);
		sa(list_a, info);
	}
	else if (pos == 2)
	{
		ra(list_a, info);
		pa(list_a, list_b, info);
		sa(list_a, info);
		rra(list_a, info);
	}
	else if (pos == 4 || pos == count_list_length(*list_a))
	{
		pa(list_a, list_b, info);
		ra(list_a, info);
	}
	else if (pos == 3)
	{
		rra(list_a, info);
		pa(list_a, list_b, info);
		ra(list_a, info);
		ra(list_a, info);
	}
}

static void	push_back(t_node **list_a, t_node **list_b, t_info *info)
{
	int		pos;
	t_node	*tmp;

	pos = 0;
	tmp = *list_a;
	while (tmp)
	{
		if (tmp->num > info->b_first)
			break ;
		pos++;
		tmp = tmp->next;
	}
	if (pos == 0)
		pa(list_a, list_b, info);
	else
		push_back2(list_a, list_b, info, pos);
}

void	five_sort(t_node **list_a, t_node **list_b, t_info *info)
{
	while (count_list_length(*list_a) > 3)
		pb(list_a, list_b, info);
	three_sort(list_a, info);
	while (*list_b)
		push_back(list_a, list_b, info);
}
