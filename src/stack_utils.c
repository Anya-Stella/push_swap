/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:08:17 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/08 20:22:36 by tishihar         ###   ########.fr       */
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

t_node	*pop_top(t_stack *stack_)
{
	t_node	*temp;

	if (!stack_ || stack_->size == 0)
		return (NULL);
	
	// pop
	temp = stack_->top;

	if (stack_->size == 1)
	{
		stack_->bottom = NULL;
		stack_->top = NULL;
	}
	else
	{
		stack_->top = stack_->top->next;
		stack_->top->prev = NULL;
	}
	stack_->size--;

	// seikei
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}

t_node	*pop_bottom(t_stack *stack_)
{
	t_node	*temp;

	if (!stack_ || stack_->size == 0)
		return (NULL);
	
	temp = stack_->bottom;

	if (stack_->size == 1)
	{
		stack_->bottom = NULL;
		stack_->top = NULL;
	}
	else
	{
		stack_->bottom = stack_->bottom->prev;
		stack_->bottom->next = NULL;
	}
	stack_->size--;

	// seikei
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}