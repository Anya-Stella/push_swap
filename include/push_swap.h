/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:53:58 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/08 15:43:34 by tishihar         ###   ########.fr       */
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

// stack_utils
void	init_stack(t_stack *stack_);
void	vacuum_stack_nodes(t_stack *stack_);
t_node	*create_node(int value);
void	push_top(t_stack *stack_, t_node *node_);
void	push_bottom(t_stack *stack_, t_node *node_);

// validation
bool	validation_atoi(const char *str, int *out);
bool	is_already_exist(t_stack *stack_, int value);
#endif