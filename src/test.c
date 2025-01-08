/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:31:11 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/08 16:33:14 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*curr;

	if (!stack || !stack->top)
	{
		printf("Stack is empty\n");
		return ;
	}
	curr = stack->top;
	while (curr)
	{
		printf("%d\n", curr->value);
		curr = curr->next;
	}
}