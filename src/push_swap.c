/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:50:56 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/13 14:38:25 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			// targetよりもcurrが小さい場合rank++
			if (target->value > curr->value)
				rank++;
			curr = curr->next;
		}

		target->rank = rank;
		target = target->next;
	}

	return (true);
}

int		get_max_bits(int size)
{
	int	max_bits = 0;

	while ((size >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort_helper(t_stack *a, t_stack *b, int max_bits)
{
	int	curr_bit;
	int	bit;
	int	size;
	int	count;

	curr_bit = 0;
	size = a->size;
	while (curr_bit < max_bits)// 0 < 7
	{
		count = size;// 500
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

// mainのソート関数：（入力：スタック, 出力：完了？）
void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;


	//　まずはランクつけO(n^2)
	if (!assign_rank(a))
		return ;

	// 最大bit数
	max_bits = get_max_bits(a->size);
	
	// ランクをradix sortでソートしていく
	radix_sort_helper(a, b, max_bits);
	
	return ;
}