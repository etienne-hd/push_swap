/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:59:38 by ehode             #+#    #+#             */
/*   Updated: 2025/11/22 17:36:06 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "solver.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	parse(argc, argv, &stack_a, &stack_b);
	if (!stack_a || !stack_b)
		return (1);
	if (stack_a->size > 1 && !stack_is_solved(stack_a))
		solve(stack_a, stack_b);
	stack_destroy(&stack_a);
	stack_destroy(&stack_b);
}
