/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:45:49 by ehode             #+#    #+#             */
/*   Updated: 2025/11/02 23:39:15 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_top(t_stack *stack, size_t index)
{
	int	value;

	value = stack->values[index];
	while (value != stack->values[stack->len - 1])
	{
		if (index + 1 > stack->len / 2)
			stack_r(stack);
		else
			stack_revr(stack);
	}
}

static void	sort_three_number(t_stack *stack)
{
	size_t	i;
	size_t	big_i;
	size_t	low_i;

	big_i = 0;
	low_i = 0;
	i = 0;
	while (i < 3 && stack->len == 3)
	{
		if (stack->values[i] > stack->values[big_i])
			big_i = i;
		if (stack->values[i] < stack->values[low_i])
			low_i = i;
		i++;
	}
	if ((low_i == 2 && big_i == 0) || (stack->len != 3))
		return ;
	if (low_i == 0 && big_i != 2)
		stack_revr(stack);
	else if (big_i == 2)
		stack_r(stack);
	else
		stack_s(stack);
	sort_three_number(stack);
}

static int	get_target_index(t_stack *stack_a, int value)
{
	size_t	i;
	int		target_i;

	i = 0;
	target_i = -1;
	while (i < stack_a->len)
	{
		if (
			stack_a->values[i] > value
			&& (target_i == -1
				|| stack_a->values[target_i] > stack_a->values[i])
		)
			target_i = i;
		i++;
	}
	if (target_i == -1)
		target_i = get_min_number_index(stack_a);
	return (target_i);
}

static int	get_best_stack_b_index(t_stack *stack_a, t_stack *stack_b)
{
	size_t	i;
	int		best_cost;
	int		best_index;
	int		total;
	int		target_index;

	i = 0;
	best_cost = 2147483647;
	best_index = -1;
	while (i < stack_b->len)
	{
		target_index = get_target_index(stack_a, stack_b->values[i]);
		total = get_cost(target_index, stack_a) + get_cost(i, stack_b);
		if (total <= best_cost)
		{
			best_cost = total;
			best_index = i;
		}
		i++;
	}
	return (best_index);
}

void	solve(t_stack *stack_a, t_stack *stack_b)
{
	int	best_index;
	int	target_i;
	int	min_value;

	push_until_three(stack_a, stack_b);
	sort_three_number(stack_a);
	while (stack_b->len)
	{
		best_index = get_best_stack_b_index(stack_a, stack_b);
		rotate_to_top(stack_b, best_index);
		target_i = get_target_index(stack_a, stack_b->values[stack_b->len - 1]);
		rotate_to_top(stack_a, target_i);
		stack_p(stack_a, stack_b);
	}
	min_value = get_min_number_index(stack_a);
	rotate_to_top(stack_a, min_value);
}
