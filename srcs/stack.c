/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:03:44 by ehode             #+#    #+#             */
/*   Updated: 2025/10/30 21:15:19 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int length, char id)
{
	t_stack	*stack;
	int		*values;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	values = malloc(sizeof(int) * length);
	if (!values)
	{
		free(stack);
		return (NULL);
	}
	stack->id = id;
	stack->len = 0;
	stack->size = length;
	stack->values = values;
	return (stack);
}

void	stack_add(t_stack *stack, int value)
{
	stack->values[stack->size - stack->len - 1] = value;
	stack->len++;
}

void	stack_destroy(t_stack **stack)
{
	free((*stack)->values);
	free(*stack);
	*stack = NULL;
}
