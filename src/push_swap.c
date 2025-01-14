/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:50:56 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/14 13:07:56 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// o(n^2)
bool	assign_rank(t_stack *a)
{
	t_node	*target;
	t_node	*curr;
	int		rank;

	if (!a)
		return (false);
	target = a->top;
	while (target)
	{
		rank = 1;
		curr = a->top;
		while (curr)
		{
			if (target->value > curr->value)
				rank++;
			curr = curr->next;
		}
		target->rank = rank;
		target = target->next;
	}
	return (true);
}

static	int		get_max_bits(int size)
{
	int	max_bits = 0;

	while ((size >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static	void	radix_sort_helper(t_stack *a, t_stack *b, int max_bits)
{
	int	curr_bit;
	int	bit;
	int	size;
	int	count;

	curr_bit = 0;
	size = a->size;
	while (curr_bit < max_bits)
	{
		count = size;
		while (count--)
		{
			if (is_sorted(a) && a->size == size)
				return ;
			bit = (a->top->rank >> curr_bit) & 1;
			if (bit == 0)
				pb(a, b);
			else
				ra(a);
		}
		while (b->size)
			pa(a, b);
		curr_bit++;
	}
}

// mainのソート関数：（入力：スタック）
void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;

	if (!assign_rank(a))
		return ;
	max_bits = get_max_bits(a->size);
	radix_sort_helper(a, b, max_bits);
	return ;
}
