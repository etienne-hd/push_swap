/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:27:06 by ehode             #+#    #+#             */
/*   Updated: 2025/10/30 21:20:06 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stacks_show(t_stack *stack_a, t_stack *stack_b)
{
	size_t	size;
	size_t	i;

	if (stack_a->len > stack_b->len)
		size = stack_a->len;
	else
		size = stack_b->len;
	i = 0;
	if (size > 0)
		ft_dprintf(2, "\n");
	while (i < size)
	{
		if (stack_a->len > size - i - 1)
			ft_dprintf(2, "%d\t", stack_a->values[size - i - 1]);
		else
			ft_dprintf(2, "\t");
		if (stack_b->len > size - i - 1)
			ft_dprintf(2, "%d\t", stack_b->values[size - i - 1]);
		else
			ft_dprintf(2, "\t");
		ft_dprintf(2, "\n");
		i++;
	}
	ft_dprintf(2, "_\t_\n%c (%d)\t%c (%d)\n", stack_a->id, stack_a->len,
		stack_b->id, stack_b->len);
}
