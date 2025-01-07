/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackUtils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:41:32 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/07 18:41:43 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_stack(t_stack *stackPointer)
{
	stackPointer->top = NULL;
	stackPointer->bottom = NULL;
	stackPointer->size = 0;
}