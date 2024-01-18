/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:46:10 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/16 10:40:07 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_chunk	find_chuncks(t_info *info, int chunk_choice, int chunk_count)
{
	int		range;
	t_chunk	chunk;

	range = info->largest_val - info->smallest_val;
	chunk.min = info->smallest_val + (range / chunk_count * chunk_choice);
	chunk.max = chunk.min + (range / chunk_count);
	return (chunk);
}

static int	chunk_exist(t_chunk chunk, t_node **a)
{
	t_node	*tmp;
	int		first;
	int		last;

	tmp = *a;
	first = 0;
	last = 0;
	while (tmp && ++first && ++last)
	{
		if (tmp->num >= chunk.min && tmp->num < chunk.max)
			break ;
		tmp = tmp->next;
	}
	while (tmp && ++last)
	{
		if (tmp->num >= chunk.min && tmp->num < chunk.max)
			break ;
		tmp = tmp->next;
	}
	if (tmp && first < count_list_length(*a) - last)
		return (1);
	else if (tmp)
		return (-1);
	return (0);
}

static void	push_chunk(t_chunk chunk, t_node **a, t_node **b, t_info *info)
{
	int	direction;

	direction = chunk_exist(chunk, a);
	while (direction)
	{
		if (direction == 1)
		{
			while (!(info->a_first >= chunk.min && info->a_first < chunk.max))
				ra(a, info);
		}
		else if (direction == -1)
		{
			while (!(info->a_first >= chunk.min && info->a_first < chunk.max))
				rra(a, info);
		}
		pb(a, b, info);
		direction = chunk_exist(chunk, a);
	}
}

static void	push_largest(t_node **list_a, t_node **list_b, t_info *info)
{
	int		largest;
	int		i;
	int		pos;
	t_node	*tmp;

	largest = info->b_first;
	tmp = *list_b;
	i = 0;
	pos = 0;
	while (tmp)
	{
		if (tmp->num > largest)
		{
			pos = i;
			largest = tmp->num;
		}
		tmp = tmp->next;
		i++;
	}
	while (info->b_first != largest && pos <= i / 2)
		rb(list_b, info);
	while (info->b_first != largest && pos > i / 2)
		rrb(list_b, info);
	pa(list_a, list_b, info);
}

void	hundred_swap(t_node **list_a, t_node **list_b, t_info *info, int num)
{
	int	i;
	int	num_of_chunks;

	i = 0;
	num_of_chunks = num;
	while (i < num_of_chunks)
	{
		push_chunk(find_chuncks(info, i, num_of_chunks), list_a, list_b, info);
		i++;
	}
	while (*list_a)
		pb(list_a, list_b, info);
	while (*list_b)
		push_largest(list_a, list_b, info);
}
