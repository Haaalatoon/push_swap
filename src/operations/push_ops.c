/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:33:23 by hrhilane          #+#    #+#             */
/*   Updated: 2025/03/29 00:33:27 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*src_node;

	if (!*src)
		return ;
	src_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	src_node->prev = NULL;
	if (!*dst)
	{
		*dst = src_node;
		src_node->next = NULL;
	}
	else
	{
		src_node->next = *dst;
		src_node->next->prev = src_node;
		*dst = src_node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (!print)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push(b, a);
	if (!print)
		write(1, "pb\n", 3);
}
