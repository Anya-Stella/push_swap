/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:50:56 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/12 21:14:36 by tishihar         ###   ########.fr       */
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

void	radix_sort_helper(t_stack *a, t_stack *b)
{

}

// mainのソート関数：（入力：スタック, 出力：完了？）
void	radix_sort(t_stack *a, t_stack *b)
{
	//　まずはランクつけO(n^2)
	if (!assign_rank(a))
		return ;
		
	// ランクをradix sortでソートしていく
	radix_sort_helper(a, b);
	
	return ;
}