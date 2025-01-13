/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:57:52 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/13 17:39:21 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort_v3(t_stack *a)
{
	if (!assign_rank(a))
		return ;
	if (a->top->rank == 1)
	{
		sa(a);
		rra(a);
	}
	else if (a->top->rank == 2)
	{
		if (a->top->next->rank == 1)
			sa(a);
		if (a->top->next->rank == 3)
			rra(a);
	}
	else if (a->top->rank == 3)
	{
		if (a->top->next->rank == 1)
			ra(a);
		if (a->top->next->rank == 2)
		{
			sa(a);
			rra(a);
		}
	}
}
// void	simple_sort_v5()
// {
	
// }

