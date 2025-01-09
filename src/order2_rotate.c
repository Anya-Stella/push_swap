/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order2_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:09:40 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/09 15:43:39 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate a
void	ra(t_stack *a)
{
	t_node	*node;

	node = pop_top(a);
	if (!node)
		return ;
	if (push_bottom(a, node))
		write (1, "ra\n", 3);
}

// rotate b
void	rb(t_stack *b)
{
	t_node	*node;

	node = pop_top(b);
	if (!node)
		return ;
	if (push_bottom(b, node))
		write (1, "rb\n", 3);
}

// do ra and rb
void	rr(t_stack *a, t_stack *b)
{
	t_node	*node_a;
	t_node	*node_b;

	if (!a || !b)
		return ;
	node_a = pop_top(a);
	node_b = pop_top(b);
	if (!node_a || !node_b)
	{
		if (node_a)
			push_top(a, node_a);
		if (node_b)
			push_top(b, node_b);
		return ;
	}
	if (push_bottom(a, node_a) && push_bottom(b, node_b))
		write (1, "rr\n", 3);
}
