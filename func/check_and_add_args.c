/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_add_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 12:45:48 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/17 11:12:59 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
	{
		if (!str[i + 1])
			return (1);
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

static int	check_dup(t_node *node, t_node *tmp, int num)
{
	if (tmp->num == num)
	{
		free(node);
		return (1);
	}
	return (0);
}

int	add_element(int num, t_node **list_a)
{
	t_node	*tmp;
	t_node	*node_to_add;

	node_to_add = add_node(num);
	if (!node_to_add)
		return (1);
	if (!(*list_a))
	{
		*list_a = node_to_add;
		return (0);
	}
	tmp = *list_a;
	while (tmp->next)
	{
		if (check_dup(node_to_add, tmp, num))
			return (1);
		tmp = tmp->next;
	}
	if (check_dup(node_to_add, tmp, num))
		return (1);
	tmp->next = node_to_add;
	return (0);
}

int	check_and_add_args(t_node **list_a, int argc, char *argv[])
{
	char		**tmp_arr;
	int			i;
	int			j;
	long long	num;

	i = 1;
	while (i < argc)
	{
		tmp_arr = ft_split(argv[i], ' ');
		if (!tmp_arr || !tmp_arr[0])
			return (1);
		j = 0;
		while (tmp_arr[j])
		{
			if (ft_atoi(tmp_arr[j], &num) || check_str(tmp_arr[j]) \
			|| add_element(num, list_a))
				return (free_all(list_a, NULL, NULL, tmp_arr));
			j++;
		}
		free_arr(tmp_arr);
		i++;
	}
	return (0);
}
