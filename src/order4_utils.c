/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order4_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:08:17 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/08 19:14:17 by tishihar         ###   ########.fr       */
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
