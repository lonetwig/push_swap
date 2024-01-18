/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:30:26 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/17 10:18:26 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_str_len(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

static void	ft_strjoin(char *s1, char *s2, char *result)
{
	char	*s2_head;

	s2_head = s2;
	while (s2 && *s2)
	{
		*result = *s2;
		result++;
		s2++;
	}
	while (s1 && *s1)
	{
		*result = *s1;
		result++;
		s1++;
	}
	*result = '\0';
	if (s2_head)
		free(s2_head);
}

static int	append_to_str(char **full_str, char *buffer)
{
	int		str_size;
	int		buffer_size;
	char	*result;

	str_size = get_str_len(*full_str);
	buffer_size = get_str_len(buffer);
	result = malloc(str_size + buffer_size + 1);
	if (!result)
		return (1);
	ft_strjoin(buffer, *full_str, result);
	*full_str = result;
	return (0);
}

static int	free_and_return(char *buffer, char *full_str)
{
	if (buffer)
		free(buffer);
	if (full_str)
		free(full_str);
	return (1);
}

int	ft_read(char **final_str)
{
	char	*buffer;
	char	*full_str;
	int		bytes_read;

	full_str = NULL;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free_and_return(buffer, full_str));
	while (1)
	{
		bytes_read = read(0, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read < 0)
			return (free_and_return(buffer, full_str));
		buffer[bytes_read] = '\0';
		if (append_to_str(&full_str, buffer))
			return (free_and_return(buffer, full_str));
		if (full_str && full_str[get_str_len(full_str) - 1] == '\n')
			check_validity(full_str, buffer);
	}
	check_validity(full_str, buffer);
	free(buffer);
	*final_str = full_str;
	return (0);
}
