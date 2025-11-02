/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:57:30 by ehode             #+#    #+#             */
/*   Updated: 2025/10/28 13:24:03 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	size_t	i;
	int		tmp;

	if (stack->len <= 1)
	{
		ft_dprintf(2, "WARNING: useless rotate\n", stack->id);
		return ;
	}
	tmp = stack->values[stack->len - 1];
	i = 0;
	while (i + 1 < stack->len)
	{
		stack->values[stack->len - i - 1] = stack->values[stack->len - i - 2];
		i++;
	}
	stack->values[0] = tmp;
}

void	stack_r(t_stack *stack)
{
	ft_printf("r%c\n", stack->id);
	rotate(stack);
}

void	stack_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("rr\n");
	rotate(stack_a);
	rotate(stack_b);
}
