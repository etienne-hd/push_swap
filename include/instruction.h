/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:31:08 by ehode             #+#    #+#             */
/*   Updated: 2025/11/22 17:35:59 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H
# include "stack.h"

void	stack_sx(t_stack *stack);
void	stack_ss(t_stack *stack_a, t_stack *stack_b);
void	stack_px(t_stack *stack_dst, t_stack *stack_src);
void	stack_rx(t_stack *stack);
void	stack_rr(t_stack *stack_a, t_stack *stack_b);
void	stack_rrx(t_stack *stack);	
void	stack_rrr(t_stack *stack_a, t_stack *stack_b);

#endif