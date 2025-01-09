/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:57:40 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/09 15:40:35 by tishihar         ###   ########.fr       */
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
	return (node_);
}
