/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:57:30 by ehode             #+#    #+#             */
/*   Updated: 2025/11/22 17:34:56 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_printf.h"

void	stack_px(t_stack *stack_dst, t_stack *stack_src)
{
	int	tmp;

	if (stack_src->len == 0)
		return ;
	ft_printf("p%c\n", stack_dst->id);
	tmp = stack_src->values[stack_src->len - 1];
	stack_dst->values[stack_dst->len] = tmp;
	stack_src->len--;
	stack_dst->len++;
}
