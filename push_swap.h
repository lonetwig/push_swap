/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 12:31:15 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/17 11:32:33 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 50

typedef struct s_node
{
	int				num;
	struct s_node	*next;
}	t_node;

typedef struct s_info
{
	int	a_first;
	int	a_last;
	int	b_first;
	int	b_last;
	int	smallest_val;
	int	largest_val;
}	t_info;

typedef struct s_chunk
{
	int	min;
	int	max;
}	t_chunk;

char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str, long long *num);
void	free_arr(char **arr);
void	free_list(t_node *list);
int		free_all(t_node **lst_a, t_node **lst_b, t_info **info, char **arr);
int		check_and_add_args(t_node **lst_a, int argc, char *argv[]);
t_node	*add_node(int num);
void	pa(t_node **list_a, t_node **list_b, t_info *info);
void	pb(t_node **list_a, t_node **list_b, t_info *info);
void	sa(t_node **list_a, t_info *info);
void	sb(t_node **list_b, t_info *info);
void	ss(t_node **list_a, t_node **list_b, t_info *info);
void	ra(t_node **list_a, t_info *info);
void	rb(t_node **list_b, t_info *info);
void	rr(t_node **list_a, t_node **list_b, t_info *info);
void	rra(t_node **list_a, t_info *info);
void	rrb(t_node **list_b, t_info *info);
void	rrr(t_node **list_a, t_node **list_b, t_info *info);
void	pa_bonus(t_node **list_a, t_node **list_b, t_info *info);
void	pb_bonus(t_node **list_a, t_node **list_b, t_info *info);
void	sa_bonus(t_node **list_a, t_info *info);
void	sb_bonus(t_node **list_b, t_info *info);
void	ss_bonus(t_node **list_a, t_node **list_b, t_info *info);
void	ra_bonus(t_node **list_a, t_info *info);
void	rb_bonus(t_node **list_b, t_info *info);
void	rr_bonus(t_node **list_a, t_node **list_b, t_info *info);
void	rra_bonus(t_node **list_a, t_info *info);
void	rrb_bonus(t_node **list_b, t_info *info);
void	rrr_bonus(t_node **list_a, t_node **list_b, t_info *info);
int		initialise_info(t_info **info, t_node *list_a);
int		check_if_sorted(t_node *list_a);
int		count_list_length(t_node *list_a);
void	two_sort(t_node **list_a, t_info *info);
void	three_sort(t_node **list_a, t_info *info);
void	five_sort(t_node **list_a, t_node **list_b, t_info *info);
void	hundred_swap(t_node **list_a, t_node **list_b, t_info *info, int num);
int		ft_read(char **final_str);
void	my_print(int fd, char *str, int length);
void	check_validity(char *s, char *b);

#endif