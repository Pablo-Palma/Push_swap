/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:14:35 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/28 23:18:23 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (error_and_free(new_argv, NULL, 1));
	if (check_input(argc, argv, &numbers))
		return (1);
	ft_push_swap(argc, &numbers);
	return (0);
}
