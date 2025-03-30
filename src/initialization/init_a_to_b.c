/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:32:55 by hrhilane          #+#    #+#             */
/*   Updated: 2025/03/29 00:33:00 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

static void	find_b_targets_for_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			closest_smaller_value;

	while (a)
	{
		closest_smaller_value = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr
				&& current_b->nbr > closest_smaller_value)
			{
				closest_smaller_value = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (closest_smaller_value == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	push_cost(t_stack_node *a, t_stack_node *b)
{
	int	a_size;
	int	b_size;

	a_size = stack_size(a);
	b_size = stack_size(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!a->above_median)
			a->push_cost = a_size - a->index;
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += b_size - a->target_node->index;
		a = a->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	long			lowest_cost;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	lowest_cost = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < lowest_cost)
		{
			lowest_cost = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	find_b_targets_for_a(a, b);
	push_cost(a, b);
	set_cheapest(a);
}
