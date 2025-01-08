/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:08:17 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/08 19:27:58 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	swap(t_stack *stack_)
{
	t_node	*first;
	t_node	*second;

	if (!stack_ || stack_->size < 2)
		return (false);

	first = stack_->top;
	second = stack_->top->next;

	//  swap
	first->next = second->next;
	if (second->next)
		second->next->prev  = first;
	second->prev = NULL;
	second->next = first;

	stack_->top = second;

	if (stack_->size == 2)
		stack_->bottom = first;
	return (true);
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
