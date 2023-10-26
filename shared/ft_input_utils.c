/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:03:23 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/26 13:29:58 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_parse_input(int argc, char **argv)
{
	int	*numbers;
	int	i;

	if (argc < 2)
		return (NULL);
	numbers = malloc((argc - 1) * sizeof(int));
	if (!numbers)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		numbers[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (numbers);
}

int	has_duplicates(int	*numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	str_validate(char *str, int sign)
{
	long long	num;
	long long	prev_num;

	num = 0;
	prev_num = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		prev_num = num;
		num = num * 10 + sign *(*str - '0');
		if (sign == 1 && (prev_num > num || num > INT_MAX))
			return (0);
		if (sign == -1 && (prev_num < num || num < INT_MIN))
			return (0);
		str++;
	}
	return (1);
}

int	sign_validate(char **str)
{
	int			sign;

	sign = 1;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	if (!ft_isdigit(**str))
		return (0);
	return (sign);
}

int	is_valid_input(int argc, char **argv)
{
	int		index;
	int		sign;
	char	*str;

	index = 1;
	while (index < argc)
	{
		str = argv[index];
		sign = sign_validate(&str);
		if (!sign || !str_validate(str, sign))
			return (0);
		index++;
	}
	return (1);
}
