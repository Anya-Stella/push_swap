/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:57:40 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/08 15:22:16 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack_)
{
	stack_->top = NULL;
	stack_->bottom = NULL;
	stack_->size = 0;
}
void	vacuum_stack_nodes(t_stack *stack_)
{
	t_node	*curr;
	t_node	*next;

	if (!stack_)
		return ;

	curr = stack_->top;
	
	while (curr)
	{
		next = curr->next;

		free(curr);
		curr = next;
	}

	init_stack(stack_);
}

t_node	*create_node(int value)
{
	t_node	*node_;

	node_ = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!node_)
		return (NULL);
	node_->value = value;
	node_->prev = NULL;
	node_->next = NULL;

	return node_;
}

void	push_top(t_stack *stack_, t_node *node_)
{
	if (!stack_ || !node_)
		return ;
	if (stack_->size == 0)
	{
		stack_->top = node_;
		stack_->bottom = node_;
	}
	else
	{
		node_->next = stack_->top;
		stack_->top->prev = node_;
		stack_->top = node_;
	}
	stack_->size += 1;
}

void	push_bottom(t_stack *stack_, t_node *node_)
{
	if (!stack_ || !node_)
		return ;
	if (stack_->size == 0)
	{
		stack_->top = node_;
		stack_->bottom = node_;
	}
	else
	{
		node_->prev = stack_->bottom;
		stack_->bottom->next = node_;
		stack_->bottom = node_;
	}
	stack_->size += 1;
}
