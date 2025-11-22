/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:30:29 by ehode             #+#    #+#             */
/*   Updated: 2025/11/22 17:35:54 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H
# include "stack.h"
# include "stddef.h"

void	solve(t_stack *stack_a, t_stack *stack_b);
void	push_until_three(t_stack *stack_a, t_stack *stack_b);
int		get_cost(size_t index, t_stack *stack);
int		get_min_number_index(t_stack *stack);

#endif