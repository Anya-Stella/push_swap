/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:35:23 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/08 16:32:02 by tishihar         ###   ########.fr       */
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

int	main(int argc, char **argv)
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
	//ここまできたらスタックAは準備完了
	print_stack(&st_a);

	return (0);
}


