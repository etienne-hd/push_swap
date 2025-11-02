/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:14:43 by ehode             #+#    #+#             */
/*   Updated: 2025/10/30 00:17:08 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_check_duplicate(t_stack *stack)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < stack->len)
	{
		j = i + 1;
		while (j < stack->len)
		{
			if (stack->values[i] == stack->values[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	stack_is_solved(t_stack *stack)
{
	size_t	i;

	if (stack->len != stack->size)
		return (0);
	i = 0;
	while (i + 1 < stack->len)
	{
		if (stack->values[i] < stack->values[i + 1])
			return (0);
		i++;
	}
	return (1);
}
