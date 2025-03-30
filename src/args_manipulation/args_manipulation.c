/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:16:12 by hrhilane          #+#    #+#             */
/*   Updated: 2025/03/29 20:16:14 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\f' || c == '\v');
}

char	*join_arguments(int argc, char **argv)
{
	char	*result;
	char	*temp;
	int		i;

	result = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		temp = ft_strjoin(result, " ");
		free(result);
		if (!temp)
			return (NULL);
		result = ft_strjoin(temp, argv[i]);
		free(temp);
		if (!result)
			return (NULL);
		i++;
	}
	return (result);
}

int	process_args(int argc, char **argv, char ***temp_args)
{
	char	*joined_args;

	joined_args = NULL;
	if (argc == 1)
		return (1);
	if (argc == 2)
	{
		*temp_args = ft_split(argv[1], ' ');
		if (!*temp_args)
			return (1);
	}
	else
	{
		joined_args = join_arguments(argc, argv);
		if (!joined_args)
			return (1);
		*temp_args = ft_split(joined_args, ' ');
		free(joined_args);
		if (!*temp_args)
			return (1);
	}
	return (0);
}

int	handle_errors(char **temp_args, t_stack_node **a)
{
	if (temp_args)
		leaks_no_no(temp_args);
	if (a)
		clear_stack(a);
	return (write(2, "Error\n", 6), 1);
}
