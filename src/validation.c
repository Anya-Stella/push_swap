/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:21:31 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/08 15:54:27 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 入力のヴァリデートをみながらatoi
bool	validation_atoi(const char *str, int *out)
{
	int	result;
	int	digit;
	int	border;
	int	lim;
	int	sign;

	sign = -2 * (*str == '-') + 1;
	str += (*str == '-' || *str == '+');
	result = 0;
	border = INT_MAX / 10;
	lim = INT_MAX % 10 + (1 - sign) / 2;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		digit = *str - '0';
		if ((result > border) || (result == border && digit > lim))
			return (false);
		result = (10 * result) + digit;
		str++;
	}
	*out = (int)(sign * result);
	return (true);
}

// 挿入する前にその数字がスタックに存在しないかを見る関数. すたっく　いんと
bool	is_already_exist(t_stack *stack_, int value)
{
	t_node	*curr;

	curr = stack_->top;
	while (curr)
	{
		if (curr->value == value)
			return (true);
		curr = curr->next;
	}
	return (false);
}
