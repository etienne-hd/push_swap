/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:58:58 by ehode             #+#    #+#             */
/*   Updated: 2025/10/30 22:19:54 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack
{
	char	id;
	size_t	size;
	size_t	len;
	int		*values;
}				t_stack;
t_stack	*stack_new(int length, char id);
void	stack_add(t_stack *stack, int value);
void	stack_destroy(t_stack **stack);
void	stacks_show(t_stack *stack_1, t_stack *stack_2);

// Instruction
void	stack_s(t_stack *stack);
void	stack_ss(t_stack *stack_a, t_stack *stack_b);
void	stack_p(t_stack *stack_dst, t_stack *stack_src);
void	stack_r(t_stack *stack);
void	stack_rr(t_stack *stack_a, t_stack *stack_b);
void	stack_revr(t_stack *stack);	
void	stack_revrr(t_stack *stack_a, t_stack *stack_b);

// Solver
void	solve(t_stack *stack_a, t_stack *stack_b);
void	push_until_three(t_stack *stack_a, t_stack *stack_b);
int		get_cost(size_t index, t_stack *stack);
int		get_min_number_index(t_stack *stack);

// Verification
int		stack_check_duplicate(t_stack *stack);
int		stack_is_solved(t_stack *stack);

#endif