/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:16:46 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/16 13:24:06 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_list(t_node *list)
{
	t_node	*tmp;

	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}

int	free_all(t_node **lst_a, t_node **lst_b, t_info **info, char **arr)
{
	if (lst_a)
		free_list(*lst_a);
	if (lst_b)
		free_list(*lst_b);
	if (arr)
		free_arr(arr);
	if (info && *info)
		free(*info);
	return (1);
}
