/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:04:28 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/17 10:41:00 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	sort_list_bonus(t_node **a, t_node **b, t_info *info, char *cmd)
{
	if (cmd[0] == 'p' && cmd[1] == 'a' && cmd[2] == '\0')
		pa_bonus(a, b, info);
	else if (cmd[0] == 'p' && cmd[1] == 'b' && cmd[2] == '\0')
		pb_bonus(a, b, info);
	else if (cmd[0] == 'r' && cmd[1] == 'a' && cmd[2] == '\0')
		ra_bonus(a, info);
	else if (cmd[0] == 'r' && cmd[1] == 'b' && cmd[2] == '\0')
		rb_bonus(b, info);
	else if (cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == '\0')
		rr_bonus(a, b, info);
	else if (cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == 'a')
		rra_bonus(a, info);
	else if (cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == 'b')
		rrb_bonus(b, info);
	else if (cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == 'r')
		rrr_bonus(a, b, info);
	else if (cmd[0] == 's' && cmd[1] == 'a' && cmd[2] == '\0')
		sa_bonus(a, info);
	else if (cmd[0] == 's' && cmd[1] == 'b' && cmd[2] == '\0')
		sb_bonus(b, info);
	else if (cmd[0] == 's' && cmd[1] == 's' && cmd[2] == '\0')
		ss_bonus(a, b, info);
	else
		return (1);
	return (0);
}

static void	checker_bonus(t_info **info, t_node **list_a, t_node **list_b)
{
	char	*str;
	char	**arr;
	char	**arr_head;

	if (ft_read(&str))
		return ;
	arr = ft_split(str, '\n');
	arr_head = arr;
	initialise_info(info, *list_a);
	while (arr && *arr)
	{
		if (sort_list_bonus(list_a, list_b, *info, *arr))
		{
			my_print(2, "Error\n", 6);
			exit(1);
		}
		arr++;
	}
	if (*list_a && check_if_sorted(*list_a) && !*list_b)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	free(str);
	if (arr_head)
		free_arr(arr_head);
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
		my_print(2, "Error\n", 6);
	else
	{
		checker_bonus(&info, &list_a, &list_b);
		free_all(&list_a, &list_b, &info, NULL);
	}
}
