/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:28:53 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/27 14:35:39 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	execute_action(t_stack *a, t_stack *b, char *action)
{
	if (ft_strncmp(action, "sa\n", 4) == 0)
		ft_swap_silent(a);
	else if (ft_strncmp(action, "sb\n", 4) == 0)
		ft_swap_silent(b);
	else if (ft_strncmp(action, "pb\n", 4) == 0)
		ft_push(a, b);
	else if (ft_strncmp(action, "pa\n", 4) == 0)
		ft_push(b, a);
	else if (ft_strncmp(action, "ra\n", 4) == 0)
		ft_rotate_silent(a);
	else if (ft_strncmp(action, "rb\n", 4) == 0)
		ft_rotate_silent(b);
	else if (ft_strncmp(action, "ss\n", 4) == 0)
		ft_ss(a, b);
	else if (ft_strncmp(action, "rr\n", 4) == 0)
		ft_rr(a, b);
	else if (ft_strncmp(action, "rra\n", 5) == 0)
		ft_reverse_rotate_silent(a);
	else if (ft_strncmp(action, "rrb\n", 5) == 0)
		ft_reverse_rotate_silent(b);
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	checker(t_stack *a, t_stack *b)
{
	char	*action;

	action = get_next_line(STDIN_FILENO);
	while (action)
	{
		execute_action(a, b, action);
		free(action);
		action = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(a) && ft_stack_len(b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

void	stack_charger(int *numbers, int len)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	a = ft_init_stack();
	b = ft_init_stack();
	if (!a || !b)
	{
		ft_putstr_fd("Error\n", 2);
		ft_free_stack(a);
		ft_free_stack(b);
		exit(EXIT_FAILURE);
	}
	a->identifier = 'a';
	b->identifier = 'b';
	i = len - 1;
	while (i >= 0)
	{
		ft_push_stack(a, numbers[i]);
		i--;
	}
	checker(a, b);
	ft_free_stack(a);
	ft_free_stack(b);
}

int	main(int argc, char **argv)
{
	int	*numbers;

	if (argc < 2)
		return (EXIT_SUCCESS);
	if (argc > ARG_MAX)
	{
		ft_putstr_fd("Error: Too many arguments.\n", 2);
		return (EXIT_FAILURE);
	}
	if (!is_valid_input(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (EXIT_FAILURE);
	}
	numbers = ft_parse_input(argc, argv);
	if (has_duplicates(numbers, argc -1))
	{
		ft_putstr_fd("Error\n", 2);
		free(numbers);
		return (EXIT_FAILURE);
	}
	stack_charger(numbers, argc - 1);
	if (numbers)
		free(numbers);
	return (EXIT_SUCCESS);
}
