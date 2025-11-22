/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:58:58 by ehode             #+#    #+#             */
/*   Updated: 2025/11/22 17:31:47 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stddef.h>

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

int		stack_check_duplicate(t_stack *stack);
int		stack_is_solved(t_stack *stack);

#endif