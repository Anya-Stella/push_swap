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
	if (swap(a))
		write(1, "sa\n", 3);
}

// swap b
void	sb(t_stack *b)
{
	if (swap(b))
		write(1, "sb\n", 3);
}

// do sa and sb
void	ss(t_stack *a, t_stack *b)
{
	if (swap(a) && swap(b))
		write(1, "ss\n", 3);
}

// push a
void	pa(t_stack *a)
{
	
}

// push	b
void	pb(t_stack *b)
{
	
}
