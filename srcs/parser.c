/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:03:14 by ehode             #+#    #+#             */
/*   Updated: 2025/11/02 23:37:51 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(int argc, char **argv, t_stack *stack)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			while (ft_isspace(argv[i][j]))
				j++;
			if (argv[i][j] == '\0')
				break ;
			stack_add(stack, ft_atoi(argv[i] + j));
			while (ft_isdigit(argv[i][j]) || ft_issign(argv[i][j]))
				j++;
		}
		i++;
	}
}

int	is_valid_number(char *s)
{
	long int	nb;
	int			sign;
	size_t		i;

	sign = 1;
	nb = 0;
	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(s[i]))
		return (0);
	while (ft_isdigit(s[i]))
	{
		nb = nb * 10 + s[i] - '0';
		if (nb * sign > 2147483647 || nb * sign < -2147483648)
			return (0);
		i++;
	}
	return (i);
}

int	process_str(char **argv, int i)
{
	int	size;
	int	j;
	int	length;

	size = 0;
	j = 0;
	while (argv[i][j])
	{
		while (ft_isspace(argv[i][j]))
			j++;
		if (argv[i][j] == '\0')
			break ;
		if (!((j == 0 || ft_isspace(argv[i][j - 1]))
			&& (ft_isdigit(argv[i][j]) || ft_issign(argv[i][j]))))
			return (-1);
		length = is_valid_number(argv[i] + j);
		if (length)
		{
			j += length;
			size++;
		}
		else
			return (-1);
	}
	return (size);
}

int	get_total_size(int argc, char **argv)
{
	int	i;
	int	j;
	int	size;
	int	res;

	size = 0;
	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while (ft_isspace(argv[i][j]))
			j++;
		if (argv[i][j] == '\0')
			return (-1);
		res = process_str(argv, i);
		if (res == -1)
			return (-1);
		size += res;
		i++;
	}
	return (size);
}

void	parse(int argc, char **argv,
	t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	*stack_a = NULL;
	*stack_b = NULL;
	size = get_total_size(argc, argv);
	if (size == -1)
	{
		ft_dprintf(2, "Error\n");
		return ;
	}
	*stack_a = stack_new(size, 'a');
	if (!*stack_a)
		return ;
	init_stack(argc, argv, *stack_a);
	if (stack_check_duplicate(*stack_a) == 1)
	{
		ft_dprintf(2, "Error\n");
		stack_destroy(stack_a);
		return ;
	}
	*stack_b = stack_new(size, 'b');
	if (!*stack_b)
		stack_destroy(stack_a);
}
