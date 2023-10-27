/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hundred_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:49:56 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/27 13:53:47 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_countin_chunk(t_stack *a, t_chunk_limits limits, int chunk_half)
{
	int		count_first;
	int		count_sec;
	t_node	*current;

	count_first = 0;
	count_sec = 0;
	current = NULL;
	while (current != NULL)
	{
		if (current->value < chunk_half && current->value > limits.min)
		{
			count_first += 1;
		}
		if (current->value >= chunk_half && current->value <= limits.max)
		{
			count_sec += 1;
		}
		a->top = a->top->next;
	}
	if (count_first >= count_sec)
		return (1);
	else
		return (0);
}

void	ft_move_number_to_top(t_stack *s, int number)
{
	while (s->top->value != number)
	{
		if (ft_find_position(s, number) <= ft_stack_len(s) / 2)
			ft_rotate(s);
		else
			ft_reverse_rotate(s);
	}
}

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
