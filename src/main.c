/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:14:35 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/27 01:11:43 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*numbers;
	char	**new_argv;
	int		new_argc;

	if (argc > ARG_MAX)
	{
		ft_putstr_fd("Error: Too many arguments.\n", 2);
		return (1);
	}
	if (argc == 2)
	{
		if (!one_argument_eval(argv[1], &new_argv, &new_argc) 
			|| strncmp(argv[1], "", 1) == 0)
		{
			free(new_argv);
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		argv = new_argv;
		argc = new_argc;
	}
	if (!is_valid_input(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		if (new_argv)
			free(new_argv);
		return (1);
	}
	numbers = ft_parse_input(argc, argv);
	if (!numbers)
	{
		if (new_argv)
			free(new_argv);
		return (0);
	}
	if (has_duplicates(numbers, argc -1))
	{
		ft_putstr_fd("Error\n", 2);
		if (new_argv)
			free(new_argv);
		free(numbers);
		return (1);
	}
	ft_push_swap(argc, argv);
	free(numbers);
	return (0);
}
