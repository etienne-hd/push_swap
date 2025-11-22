/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:25:35 by ehode             #+#    #+#             */
/*   Updated: 2025/11/22 17:32:04 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "instruction.h"
#include <stddef.h>

void	push_until_three(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->len > 3)
		stack_px(stack_b, stack_a);
}

int	get_cost(size_t index, t_stack *stack)
{
	index = stack->len - index - 1;
	if (index <= stack->len / 2)
		return (index);
	return (stack->len - index);
}

int	get_min_number_index(t_stack *stack)
{
	size_t	i;
	size_t	min_index;

	i = 0;
	min_index = 0;
	while (i < stack->len)
	{
		if (stack->values[min_index] > stack->values[i])
			min_index = i;
		i++;
	}
	return (min_index);
}
