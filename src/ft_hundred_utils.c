/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hundred_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:49:56 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/16 18:31:49 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_value_in_chunk(t_stack *s, int chunk_min, int chunk_max)
{
	t_node	*node;

	node = s->top;
	while (node)
	{
		if (node->value >= chunk_min && node->value <= chunk_max)
			return (1);
		node = node->next;
	}
	return (0);
}

int	ft_find_extreme_value(t_stack *s, char *type,
							int limits_min, int limits_max)
{
	t_node	*node;
	int		extreme;

	node = s->top;
	extreme = node->value;
	while (node)
	{
		if (node->value >= limits_min && node->value <= limits_max)
		{
			if ((strcmp(type, "min") == 0 && node->value < extreme)
				|| (strcmp(type, "max") == 0 && node->value > extreme))
				extreme = node->value;
		}
		node = node->next;
	}
	return (extreme);
}

int	ft_find_position(t_stack *s, int number)
{
	t_node	*current;
	int		position;

	current = s->top;
	position = 0;
	while (current)
	{
		if (current->value == number)
			return (position);
		position++;
		current = current->next;
	}
	return (-1);
}

int	find_first_hold(t_stack *a, t_chunk_limits limits)
{
	t_node	*current;

	current = a->top;
	while (current)
	{
		if (current->value >= limits.min && current->value <= limits.max)
			return (current->value);
		current = current->next;
	}
	return (INT_MIN);
}

int	find_second_hold(t_stack *a, t_chunk_limits limits)
{
	t_node	*current;

	current = a->top;
	while (current && current->next)
		current = current->next;
	while (current)
	{
		if (current->value >= limits.min && current->value <= limits.max)
			return (current->value);
		current = current->previous;
	}
	return (INT_MIN);
}
