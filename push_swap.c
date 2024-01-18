/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 12:30:39 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/16 13:25:15 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	all_sort_scenario(t_node **list_a, t_node **list_b, t_info *info)
{
	int		list_size;

	list_size = count_list_length(*list_a);
	if (list_size < 2)
		return ;
	else if (list_size == 2)
		two_sort(list_a, info);
	else if (list_size == 3)
		three_sort(list_a, info);
	else if (list_size == 4 || list_size == 5)
		five_sort(list_a, list_b, info);
	else if (list_size > 5 && list_size <= 100)
		hundred_swap(list_a, list_b, info, 5);
	else if (list_size > 100)
		hundred_swap(list_a, list_b, info, 11);
}

int	main(int argc, char *argv[])
{
	t_node	*list_a;
	t_node	*list_b;
	t_info	*info;

	list_a = NULL;
	list_b = NULL;
	info = NULL;
	if (argc == 1)
		return (0);
	if (check_and_add_args(&list_a, argc, argv))
		write(2, "Error\n", 6);
	else
	{
		if (!check_if_sorted(list_a))
		{
			initialise_info(&info, list_a);
			all_sort_scenario(&list_a, &list_b, info);
		}
		free_all(&list_a, &list_b, &info, NULL);
	}
}
