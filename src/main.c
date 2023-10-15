/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:14:35 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/15 08:24:53 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*numbers;

	if (argc > ARG_MAX)
	{
		ft_putstr_fd("Error: Too many arguments.\n", 2);
		return (1);
	}
	if (argc < 2 || !is_valid_input(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	numbers = ft_parse_input(argc, argv);
	if (has_duplicates(numbers, argc -1))
	{
		ft_putstr_fd("Error\n", 2);
		free(numbers);
		return (1);
	}
	ft_push_swap(argc, argv);
	free(numbers);
	return (0);
}
