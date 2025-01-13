/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:53:58 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/13 16:47:26 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// include
# include "libft.h"
# include "stdbool.h"

typedef struct s_node
{
	int				value;

	struct s_node	*prev;
	struct s_node	*next;

	int				rank;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

// main
int		main(int argc, char **argv);
bool	init_set_project(t_stack *stack_a, char **argv);
void	sort(t_stack *a, t_stack *b);

// stack_init_utils
void	init_stack(t_stack *stack_);
void	vacuum_stack_nodes(t_stack *stack_);
t_node	*create_node(int value);

// stack_utils
bool	swap(t_stack *stack_);
bool	push_top(t_stack *stack_, t_node *node_);
bool	push_bottom(t_stack *stack_, t_node *node_);
t_node	*pop_top(t_stack *stack_);
t_node	*pop_bottom(t_stack *stack_);

// validation
bool	validation_atoi(const char *str, int *out);
bool	is_already_exist(t_stack *stack_, int value);
bool	is_sorted(t_stack *stack);

// order
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// test
void	print_stack(t_stack *stack);

// sort
bool	assign_rank(t_stack *a);
int		get_max_bits(int size);
void	radix_sort_helper(t_stack *a, t_stack *b, int max_bits);
void	radix_sort(t_stack *a, t_stack *b);

#endif