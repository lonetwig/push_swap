/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:33:09 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/15 09:35:58 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	my_print(int fd, char *str, int length)
{
	int	result;

	result = write(fd, str, length);
	if (result < 0)
	{
		write(2, "write failed.\n", 14);
		exit(1);
	}
}
