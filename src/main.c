/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:35:23 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/14 12:20:29 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// stack
bool	init_set_project(t_stack *stack_a, char **argv)
{
	char	*curr_arg;
	int		curr_value;
	t_node	*node_;

	curr_arg = "";
	curr_value = 0;
	while (*(++argv))
	{
		curr_arg = *argv;
		if (!validation_atoi(curr_arg, &curr_value))
			return (false);
		if (is_already_exist(stack_a, curr_value))
			return (false);
		node_ = create_node(curr_value);
		if (!node_)
			return (false);
		push_bottom(stack_a, node_);
	}
	return (true);
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->size <= 2)
		simple_sort_v2(a);
	else if (a->size <= 3)
		simple_sort_v3(a);
	else if (a->size <= 5)
		simple_sort_v5(a, b);
	else
		radix_sort(a, b);
}

int		main(int argc, char **argv)
{
	t_stack	st_a;
	t_stack	st_b;

	init_stack(&st_a);
	init_stack(&st_b);
	if (argc <= 1)
		return (0);
	if (!init_set_project(&st_a, argv))
	{
		vacuum_stack_nodes(&st_a);
		write(2, "Error\n", 6);
		return (1);
	}
	if (is_sorted(&st_a))
	{
		vacuum_stack_nodes(&st_a);
		return (0);
	}
	//ここまできたらスタックAは準備完了
	
	sort(&st_a, &st_b);
	
	// print_stack(&st_a);
	vacuum_stack_nodes(&st_a);
	vacuum_stack_nodes(&st_b);

	return (0);
}
