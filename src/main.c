/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:14:35 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/31 16:51:00 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void leaks()
{
	system("leaks -q push_swap");
}*/

int	args_checker(int *argc, char ***argv, int *check_one, int **numbers)
{
	char	**new_argv;
	int		new_argc;

	*check_one = 0;
	new_argc = 0;
	new_argv = NULL;
	if (*argc > ARG_MAX)
		return (error_and_free(NULL, NULL, 1, *check_one));
	if (*argc == 2)
	{
		if (!one_argument_eval((*argv)[1], &new_argv, &new_argc)
			|| ft_strncmp((*argv)[1], "", 1) == 0)
			return (error_and_free(new_argv, NULL, 1, *check_one));
		*argv = new_argv;
		*argc = new_argc;
		*check_one = 1;
	}
	if (!is_valid_input(*argc, *argv))
		return (error_and_free(new_argv, NULL, 1, *check_one));
	if (check_input(*argc, *argv, numbers, *check_one))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	*numbers;
	int	check_one;

	check_one = 0;
	if (argc < 2)
		return (EXIT_SUCCESS);
	if (args_checker(&argc, &argv, &check_one, &numbers))
		return (1);
	ft_push_swap(argc, &numbers);
	if (check_one)
		free_array(argv);
	return (0);
}
