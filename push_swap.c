/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:32:01 by hrhilane          #+#    #+#             */
/*   Updated: 2025/03/29 00:32:03 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**temp_args;

	a = NULL;
	b = NULL;
	temp_args = NULL;
	if (process_args(argc, argv, &temp_args) || (temp_args && !temp_args[0]))
		return (handle_errors(temp_args, NULL));
	if (build_stack_a(&a, temp_args))
		return (handle_errors(temp_args, &a));
	if (!is_stack_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a, false);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	leaks_no_no(temp_args);
	return (clear_stack(&a), 0);
}
