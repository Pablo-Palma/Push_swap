/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input2_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:09:33 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/30 18:04:11 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_and_free(char **argv, int *numbers, int error_code)
{
	if (argv)
		free_array(argv);
	if (numbers)
		free(numbers);
	if (error_code == 1)
		ft_putstr_fd("Error\n", 2);
	exit(error_code);
}

int	check_input(int argc, char **argv, int **numbers)
{
	*numbers = ft_parse_input(argc, argv);
	if (!numbers)
		return (error_and_free(NULL, *numbers, 1));
	if (has_duplicates(*numbers, argc -1))
		return (error_and_free(NULL, *numbers, 1));
	return (0);
}

void	free_array(char **array)
{
	size_t	i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}

size_t	count_elements(char **array)
{
	size_t	count;

	count = 0;
	while (array[count])
		count++;
	return (count);
}

int	one_argument_eval(char *str, char ***new_argv, int *new_argc)
{
	char	**split_args;
	size_t	count;
	size_t	i;

	i = 0;
	split_args = ft_split(str, ' ');
	if (!split_args)
		return (0);
	count = count_elements(split_args);
	*new_argv = (char **)malloc((count + 2) * sizeof(char *));
	if (!*new_argv)
	{
		free_array(split_args);
		return (0);
	}
	(*new_argv)[0] = ft_strdup("push_swap");
	while (i < count)
	{
		(*new_argv)[i + 1] = split_args[i];
		i++;
	}
	free(split_args);
	(*new_argv)[count + 1] = NULL;
	*new_argc = count + 1;
	return (1);
}
