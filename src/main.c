/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:14:35 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/27 13:51:00 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_and_free(char **argv, int *numbers, int error_code)
{
	if (argv)
		free(argv);
	if (numbers)
		free(numbers);
	if (error_code == 1)
		ft_putstr_fd("Error\n", 2);
	exit(error_code);
}

static int	check_input(int argc, char **argv, int **numbers)
{
	*numbers = ft_parse_input(argc, argv);
	if (!numbers)
		return (error_and_free(NULL, *numbers, 1));
	if (has_duplicates(*numbers, argc -1))
		return (error_and_free(NULL, *numbers, 1));
	return (0);
}

int	main(int argc, char **argv)
{
	int		*numbers;
	char	**new_argv;
	int		new_argc;

	if (argc > ARG_MAX)
		return (error_and_free(NULL, NULL, 1));
	if (argc == 2)
	{
		if (!one_argument_eval(argv[1], &new_argv, &new_argc)
			|| ft_strncmp(argv[1], "", 1) == 0)
			return (error_and_free(new_argv, NULL, 1));
		argv = new_argv;
		argc = new_argc;
	}
	if (!is_valid_input(argc, argv))
	{
		if (new_argv)
			free(new_argv);
		return (error_and_free(NULL, NULL, 1));
	}
	if (check_input(argc, argv, &numbers))
		return (1);
	ft_push_swap(argc, argv);
	free(numbers);
	return (0);
}
