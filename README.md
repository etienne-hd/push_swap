# push_swap [![wakatime](https://wakatime.com/badge/user/b5c6762d-cdfb-4336-9c84-87845f0e1976/project/6331a50d-28a9-4e54-a1c7-9178e758a58b.svg)](https://wakatime.com/badge/user/b5c6762d-cdfb-4336-9c84-87845f0e1976/project/6331a50d-28a9-4e54-a1c7-9178e758a58b)

*push_swap is a 42 project: Sort a stack with some instruction.*

I use the **Turk** alogrithm ([more info](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)).

- **96/100** ✅

## Instructions
sa *(swap a)*: `Swap the first 2 elements at the top of stack a. Do nothing if there is only one element or none.`

sb *(swap b)*: `Swap the first 2 elements at the top of stack b. Do nothing if there is only one element or none.`

ss : `sa and sb at the same time.` 

pa *(push a)*: `Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.`

pb *(push b)*: `Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.`

ra *(rotate a)*: `Shift up all elements of stack a by 1. The first element becomes the last one.`

rb *(rotate b)*: `Shift up all elements of stack b by 1. The first element becomes the last one.`

rr : `ra and rb at the same time.`

rra *(reverse rotate a)*: `Shift down all elements of stack a by 1.
	The last element becomes the first one.`

rrb *(reverse rotate b*): `Shift down all elements of stack b by 1.
	The last element becomes the first one.`

rrr : `rra and rrb at the same time.`

## Functions
```h
void	parse(int argc, char **argv, t_stack **stack_a, t_stack **stack_b);
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
```
![42](https://img.shields.io/badge/-42-black?style=for-the-badge&logo=42&logoColor=white)