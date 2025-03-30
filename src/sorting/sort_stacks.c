/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:35:23 by hrhilane          #+#    #+#             */
/*   Updated: 2025/03/29 00:35:25 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	sync_rotate_or_rev(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node, bool is_rotate)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
	{
		if (is_rotate)
			rr(a, b, false);
		else
			rrr(a, b, false);
	}
	current_index(*a);
	current_index(*b);
}

static void	transfer_cheapest_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		sync_rotate_or_rev(a, b, cheapest_node, true);
	else if (!cheapest_node->above_median
		&& !cheapest_node->target_node->above_median)
		sync_rotate_or_rev(a, b, cheapest_node, false);
	bring_to_top(a, cheapest_node, 'a');
	bring_to_top(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}

static void	transfer_b_to_a(t_stack_node **a, t_stack_node **b)
{
	bring_to_top(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

static void	bring_min_to_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_size(*a);
	if (len_a-- > 3 && !is_stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !is_stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !is_stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		transfer_cheapest_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		transfer_b_to_a(a, b);
	}
	current_index(*a);
	bring_min_to_top(a);
}
