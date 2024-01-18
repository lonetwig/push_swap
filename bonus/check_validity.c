/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:30:32 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/17 10:50:52 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_str_len(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

static int	check_validity2(char *b)
{
	int		i;

	i = get_str_len(b);
	if (i == 2)
	{
		if ((b[0] == 's' && b[1] == 'a') || \
		(b[0] == 's' && b[1] == 'b') || \
		(b[0] == 's' && b[1] == 's') || \
		(b[0] == 'p' && b[1] == 'a') || \
		(b[0] == 'p' && b[1] == 'b') || \
		(b[0] == 'r' && b[1] == 'a') || \
		(b[0] == 'r' && b[1] == 'b') || \
		(b[0] == 'r' && b[1] == 'r'))
			return (1);
	}
	else if (i == 3)
	{
		if ((b[0] == 'r' && b[1] == 'r' && b[2] == 'a') || \
		(b[0] == 'r' && b[1] == 'r' && b[2] == 'b') || \
		(b[0] == 'r' && b[1] == 'r' && b[2] == 'r'))
			return (1);
	}
	return (0);
}

void static	free_and_exit(char *b, char *s, char **arr)
{
	my_print(2, "Error\n", 6);
	if (b)
		free(b);
	if (s)
		free(s);
	if (arr)
		free_arr(arr);
	exit(1);
}

void	check_validity(char *s, char *b)
{
	int		j;
	char	**arr;

	if (!s)
		return ;
	arr = ft_split(s, '\n');
	j = 0;
	if (get_str_len(b) == 0 && *b == '\n' && b[1] == '\0')
		free_and_exit(b, s, arr);
	while (arr[j])
	{
		if (!check_validity2(arr[j]))
			free_and_exit(b, s, arr);
		j++;
	}
	if (arr)
		free_arr(arr);
}
