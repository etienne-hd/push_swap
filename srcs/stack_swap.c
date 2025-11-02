/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:27:06 by ehode             #+#    #+#             */
/*   Updated: 2025/10/30 00:13:28 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->len < 2)
	{
		ft_dprintf(2, "WARNING: useless swap\n", stack->id);
		return ;
	}
	tmp = stack->values[stack->len - 1];
	stack->values[stack->len - 1] = stack->values[stack->len - 2];
	stack->values[stack->len - 2] = tmp;
}

void	stack_s(t_stack *stack)
{
	ft_printf("s%c\n", stack->id);
	swap(stack);
}

void	stack_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("ss\n");
	swap(stack_a);
	swap(stack_b);
}
