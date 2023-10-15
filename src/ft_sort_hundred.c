/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hundred.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:23:57 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/15 09:31:07 by pabpalma         ###   ########.fr       */
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

void	ft_sort_hundred(t_stack *a, t_stack *b)
{
	int				i;
	int				total_min;
	int				total_max;
	int				chunk_size;
	t_chunk_limits	limits;
	t_hold			hold_first;
	t_hold			hold_second;

	i = 0;
	total_min = ft_find_extreme_value(a, "min", INT_MIN, INT_MAX);
	total_max = ft_find_extreme_value(a, "max", INT_MIN, INT_MAX);
	chunk_size = (total_max - total_min) / 5;
	while (i < 5)
	{
		limits.min = total_min + (i * chunk_size);
		limits.max = limits.min + chunk_size;
		while (ft_is_value_in_chunk(a, limits.min, limits.max))
		{
			hold_first.value = 
				ft_find_extreme_value(a, "min", limits.min, limits.max);
			hold_second.value = 
				ft_find_extreme_value(a, "max", limits.min, limits.max);
			hold_first.pos = ft_find_position(a, hold_first.value);
			hold_second.pos = ft_find_position(a, hold_second.value);
			if (hold_first.pos <= hold_second.pos)
			{
				ft_move_number_to_top(a, hold_first.value);
				ft_push(a, b);
			}
			else
			{
				ft_move_number_to_top(a, hold_second.value);
				ft_push(a, b);
			}
		}
		i++;
	}
	while (b->top)
	{
		hold_first.value = ft_find_extreme_value(b, "max", INT_MIN, INT_MAX);
		hold_first.pos = ft_find_position(b, hold_first.value);
		ft_move_number_to_top(b, hold_first.value);
		ft_push(b, a);
	}
}
