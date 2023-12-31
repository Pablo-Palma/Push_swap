/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:28:53 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/31 16:58:32 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*void leaks()
{
	system("leaks -q checker");
}*/

void	execute_action(t_stack *a, t_stack *b, char *action)
{
	if (ft_strncmp(action, "sa\n", 4) == 0)
		ft_swap(a, 0);
	else if (ft_strncmp(action, "sb\n", 4) == 0)
		ft_swap(b, 0);
	else if (ft_strncmp(action, "pb\n", 4) == 0)
		ft_push(a, b, 0);
	else if (ft_strncmp(action, "pa\n", 4) == 0)
		ft_push(b, a, 0);
	else if (ft_strncmp(action, "ra\n", 4) == 0)
		ft_rotate(a, 0);
	else if (ft_strncmp(action, "rb\n", 4) == 0)
		ft_rotate(b, 0);
	else if (ft_strncmp(action, "ss\n", 4) == 0)
		ft_ss(a, b, 0);
	else if (ft_strncmp(action, "rr\n", 4) == 0)
		ft_rr(a, b, 0);
	else if (ft_strncmp(action, "rra\n", 5) == 0)
		ft_reverse_rotate(a, 0);
	else if (ft_strncmp(action, "rrb\n", 5) == 0)
		ft_reverse_rotate(b, 0);
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

int	args_checker(int argc, char ***argv, int *check_one, int **numbers)
{
	char	**new_argv;
	int		new_argc;

	*check_one = 0;
	if (argc > ARG_MAX)
		return (error_and_free(NULL, NULL, 1, *check_one));
	if (argc == 2)
	{
		if (!one_argument_eval((*argv)[1], &new_argv, &new_argc)
			|| ft_strncmp((*argv)[1], "", 1) == 0)
			return (error_and_free(NULL, NULL, 1, *check_one));
		*argv = new_argv;
		argc = new_argc;
		*check_one = 1;
	}
	if (!is_valid_input(argc, *argv))
		return (error_and_free(new_argv, NULL, 1, *check_one));
	if (check_input(argc, *argv, numbers, *check_one))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		*numbers;
	int		check_one;

	check_one = 0;
	if (argc < 2)
		return (EXIT_SUCCESS);
	if (args_checker(argc, &argv, &check_one, &numbers))
		return (1);
	stack_charger(numbers, argc - 1);
	if (numbers)
		free(numbers);
	if (check_one)
		free_array(argv);
	return (EXIT_SUCCESS);
}
