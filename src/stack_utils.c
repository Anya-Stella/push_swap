/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:57:40 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/07 19:23:01 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stackPointer)
{
	stackPointer->top = NULL;
	stackPointer->bottom = NULL;
	stackPointer->size = 0;
}

void	create_node(int	value)
{
	t_node	*nodePointer;

	// init
	nodePointer = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!nodePointer)
		return NULL;

	nodePointer->value = value;
	nodePointer->prev = NULL;
	nodePointer->next = NULL;
}
