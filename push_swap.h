/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artyavet <artyavet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:05:58 by artyavet          #+#    #+#             */
/*   Updated: 2024/06/26 22:51:43 by artyavet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	long long		num;
	int				index;
	struct s_list	*next;
}			t_list;

long long	ft_atoll(const char *str);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(long long content);
void		sort_butterfly(t_list **stack_a, t_list **stack_b, int size_nodes);
void		push_elem_b_a(t_list **stack_a, t_list **stack_b, int size_nodes);
int			vat_sqrt(int num);
int			xoranard_sqrt(int num);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst);
char		*my_strncpy(char *dest, const char *src, unsigned int n);
int			foo_sum_tar(char const *s);
int			check_sp(char **arr, const char *s, int count);
int			func_count_word(const char *s);
char		**split(char const *s);
void		set_index(t_list **stack);
int			get_position(t_list *stack, int index);
void		check(t_list **stack_a, t_list **stack_b, int count_nodes);
int			is_sorted(t_list *stack);
void		push(t_list **stack_a, t_list **stack_b);
void		push_a(t_list **stack_a, t_list **stack_b);
void		push_b(t_list **stack_a, t_list **stack_b);
void		reverse_rotate(t_list **stack);
void		reverse_rotate_a(t_list **stack_a);
void		reverse_rotate_b(t_list **stack_b);
void		reverse_rotate_a_b(t_list **stack_a, t_list **stack_b);
void		rotate(t_list **stack);
void		rotate_a(t_list **stack_a);
void		rotate_b(t_list **stack_b);
void		rotate_a_b(t_list **stack_a, t_list **stack_b);
void		sort_for_3_elements(t_list **s);
void		sort_for_5_elem(t_list **stack_a, t_list **stack_b, int count_argc);
void		swap(t_list *stack);
void		swap_a(t_list **stack_a);
void		swap_b(t_list **stack_b);
void		swap_s(t_list **stack_a, t_list **stack_b);
int			ft_strlen(char *str);
void		check_for_dublicates(t_list **stack_a);
void		exit_func(t_list **stack_a);
void		valid(int argc, char **argv, t_list **stack_a, int *count_nodes);
void		validation_helper(long long num, char *str, t_list **stack_a);
int			check_num_func(long long num, char *str);
int			check_current_line(char *str);
void		free_split_line(char **arr);
int			is_white_space(char c);
void		q_input_is_empty_or_only_spaces(char **argv);

#endif