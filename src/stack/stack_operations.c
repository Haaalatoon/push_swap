/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:36:05 by hrhilane          #+#    #+#             */
/*   Updated: 2025/03/29 00:36:07 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '\f'
		|| *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

static void	append_node(t_stack_node **stack, int num_val)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->nbr = num_val;
	new_node->cheapest = 0;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

// void	build_stack_a(t_stack_node **a, char **argv)
// {
// 	long	num_val;
// 	int		i;

// 	i = 0;
// 	while (argv[i])
// 	{
// 		if (is_valid_syntax(argv[i]))
// 		{
// 			write(2, "Error: Invalid number\n", 23);
// 			handle_error_and_exit(a);
// 		}
// 		num_val = ft_atol(argv[i]);
// 		if (num_val < INT_MIN || num_val > INT_MAX)
// 			handle_error_and_exit(a);
// 		if (has_duplicate(*a, num_val))
// 			handle_error_and_exit(a);
// 		append_node(a, (int)num_val);
// 		i++;
// 	}
// }

int	build_stack_a(t_stack_node **a, char **argv)
{
	long	num_val;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (is_valid_syntax(argv[i]))
			return (1);
		num_val = ft_atol(argv[i]);
		if (num_val < INT_MIN || num_val > INT_MAX)
			return (1);
		if (has_duplicate(*a, num_val))
			return (1);
		append_node(a, num_val);
		i++;
	}
	return (0);
}

void	bring_to_top(t_stack_node **stack, t_stack_node *top_node,
		char stack_id)
{
	while (*stack != top_node)
	{
		if (stack_id == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_id == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
