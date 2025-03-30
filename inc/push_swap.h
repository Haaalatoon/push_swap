/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:30:22 by hrhilane          #+#    #+#             */
/*   Updated: 2025/03/29 00:30:29 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

// Stack Node
typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// Initialization
void					current_index(t_stack_node *stack);
void					set_cheapest(t_stack_node *stack);
void					init_nodes_a(t_stack_node *a, t_stack_node *b);
void					init_nodes_b(t_stack_node *a, t_stack_node *b);

//  Operations
void					pa(t_stack_node **a, t_stack_node **b, bool print);
void					pb(t_stack_node **b, t_stack_node **a, bool print);
void					ra(t_stack_node **a, bool print);
void					rb(t_stack_node **b, bool print);
void					rr(t_stack_node **a, t_stack_node **b, bool print);
void					rra(t_stack_node **a, bool print);
void					rrb(t_stack_node **b, bool print);
void					rrr(t_stack_node **a, t_stack_node **b, bool print);
void					sa(t_stack_node **a, bool print);
void					sb(t_stack_node **b, bool print);
void					ss(t_stack_node **a, t_stack_node **b, bool print);

// Parsing
char					**ft_split(char *s, char c);
int						is_valid_syntax(char *str_nbr);
int						has_duplicate(t_stack_node *a, int n);
void					clear_stack(t_stack_node **stack);
void					handle_error_and_exit(t_stack_node **a);
void					leaks_no_no(char **arr);

// Sorting
void					sort_three(t_stack_node **a);
void					sort_stacks(t_stack_node **a, t_stack_node **b);

// Stack
int						build_stack_a(t_stack_node **a, char **argv);
void					bring_to_top(t_stack_node **stack,
							t_stack_node *top_node, char stack_id);
int						stack_size(t_stack_node *stack);
t_stack_node			*find_last(t_stack_node *stack);
bool					is_stack_sorted(t_stack_node *stack);
t_stack_node			*find_min(t_stack_node *stack);
t_stack_node			*find_max(t_stack_node *stack);
t_stack_node			*get_cheapest(t_stack_node *stack);

// ARGS Manipulation
char					*join_arguments(int argc, char **argv);
char					*ft_strjoin(char *s1, char *s2);
char					*ft_strdup(const char *s);
int						process_args(int argc, char **argv, char ***temp_args);
int						ft_is_whitespace(char c);
int						handle_errors(char **temp_args, t_stack_node **a);

#endif
