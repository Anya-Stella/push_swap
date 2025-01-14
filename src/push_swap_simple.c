/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:57:52 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/14 12:41:20 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 2以下の場合のソート
void	simple_sort_v2(t_stack *a)
{
	if (a->size == 1)
		return ;
	if (a->top->value > a->top->next->value)
		sa(a);
}

// 3以下の場合のソート
void	simple_sort_v3(t_stack *a)
{
	int top;
	int mid;
	int bot;

	top = a->top->value;
	mid = a->top->next->value;
	bot = a->bottom->value;
	
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top > mid && mid > bot && top > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a);
}

// 要素数４，５での最適化プッシュ(簡易版)
static void	push_min(t_stack *a, t_stack*b)
{
	t_node	*curr;
	int		min;


	// min = 5
	curr = a->top;
	min = a->top->rank;
	while (curr)
	{
		if (curr->rank < min)
			min = curr->rank;
		curr = curr->next;
	}
	// 最小値の場所まで最短で回す
	if (a->bottom->rank == min || a->bottom->prev->rank == min)
	{
		while (a->top->rank != min)
			rra(a);		
	}
	else
	{
		while (a->top->rank != min)
			ra(a);
	}
	pb(a, b);
}

// 5以下の場合のソート
void	simple_sort_v5(t_stack *a, t_stack*b)
{
	if (!assign_rank(a))
		return ;
	push_min(a, b);
	push_min(a, b);
	simple_sort_v3(a);
	pa(a, b);
	pa(a, b);
}

