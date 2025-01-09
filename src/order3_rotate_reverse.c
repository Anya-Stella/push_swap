/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order3_rotate_reverse.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:11:45 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/09 15:36:26 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// reverse rotate a
void	rra(t_stack *a)
{
	t_node	*node;

	node = pop_bottom(a);
	if (!node)
		return ;
	
	if (push_top(a, node))
		write (1, "rra\n", 3);
}

// reverse rotate b
void	rrb(t_stack *b)
{
	t_node	*node;

	node = pop_bottom(b);
	if (!node)
		return ;
	
	if (push_top(b, node))
		write (1, "rrb\n", 3);
}

// do rra and rrb
void	rrr(t_stack *a, t_stack *b)
{
	t_node	*node_a;
	t_node	*node_b;

	if (!a || !b)
		return ;

	node_a = pop_bottom(a);
	node_b = pop_bottom(b);

	if (!node_a || !node_b)
	{
		if (node_a)
			push_bottom(a, node_a);
		if (node_b)
			push_bottom(b, node_b);

		return ;
	}

	if (push_top(a, node_a) && push_top(b, node_b))
		write (1, "rrr\n", 3);
}
