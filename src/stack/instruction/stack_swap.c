/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:27:06 by ehode             #+#    #+#             */
/*   Updated: 2025/11/22 17:35:13 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_printf.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->len < 2)
		return ;
	tmp = stack->values[stack->len - 1];
	stack->values[stack->len - 1] = stack->values[stack->len - 2];
	stack->values[stack->len - 2] = tmp;
}

void	stack_sx(t_stack *stack)
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
