/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:57:30 by ehode             #+#    #+#             */
/*   Updated: 2025/11/22 17:35:08 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_printf.h"

static void	reverse_rotate(t_stack *stack)
{
	size_t	i;
	int		tmp;

	if (stack->len <= 1)
		return ;
	tmp = stack->values[0];
	i = 0;
	while (i + 1 < stack->len)
	{
		stack->values[i] = stack->values[i + 1];
		i++;
	}
	stack->values[stack->len - 1] = tmp;
}

void	stack_rrx(t_stack *stack)
{
	ft_printf("rr%c\n", stack->id);
	reverse_rotate(stack);
}

void	stack_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("rrr\n");
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
