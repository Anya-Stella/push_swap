/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order1_pushswap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:05:10 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/08 17:08:03 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap a
void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (!a || a->size < 2)
		return ;

	first = a->top;
	second = a->top->next;

	//  swap
	first->next = second->next;
	if (second->next)
		second->next->prev  = first;
	second->prev = NULL;
	second->next = first;

	a->top = second;

	if (a->size == 2)
		a->bottom = first;
	
	write(1, "sa\n", 3);
}

// swap b
void	sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (!b || b->size < 2)
		return ;
	

	first = b->top;
	second = b->top->next;

	//  swap
	first->next = second->next;
	if (second->next)
		second->next->prev  = first;
	second->prev = NULL;
	second->next = first;

	b->top = second;

	if (b->size == 2)
		b->bottom = first;
	
	write(1, "sb\n", 3);
	
}

// do sa and sb
void	ss(t_stack *a, t_stack *b)
{

}

// push a
void	pa(t_stack *a)
{

}

// push	b
void	pb(t_stack *b)
{
	
}
