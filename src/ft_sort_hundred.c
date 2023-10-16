/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hundred.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:23:57 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/15 10:45:24 by pabpalma         ###   ########.fr       */
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

void	handle_chunk(t_stack *a, t_stack *b, t_chunk_limits limits)
{
	int	hold_first;
	int	hold_second;
	int	pos_first;
	int	pos_second;

	while (ft_is_value_in_chunk(a, limits.min, limits.max))
	{
		hold_first = find_first_hold(a, limits);
		hold_second = find_second_hold(a, limits);
		pos_first = ft_find_position(a, hold_first);
		pos_second = ft_find_position(a, hold_second);
		if (abs(pos_first - ft_stack_len(a) / 2 
				< abs(pos_second - ft_stack_len(a) / 2)))
		{
			ft_move_number_to_top(a, hold_first);
			ft_push(a, b);
		}
		else
		{
			ft_move_number_to_top(a, hold_second);
			ft_push(a, b);
		}
	}
}

void	ft_sort_hundred(t_stack *a, t_stack *b, int chunk_count)
{
	int				i;
	int				total_min;
	int				total_max;
	int				chunk_size;
	int				max_val;
	t_chunk_limits	limits;

	i = 0;
	total_min = ft_find_extreme_value(a, "min", INT_MIN, INT_MAX);
	total_max = ft_find_extreme_value(a, "max", INT_MIN, INT_MAX);
	chunk_size = (total_max - total_min) / chunk_count;
	while (i < chunk_count)
	{
		limits.min = total_min + (i * chunk_size);
		if (i == chunk_count - 1)
			limits.max = total_max;
		else
			limits.max = limits.min + chunk_size;
		handle_chunk(a, b, limits);
		i++;
	}
	while (b->top)
	{
		max_val = ft_find_extreme_value(b, "max", INT_MIN, INT_MAX);
		ft_move_number_to_top(b, max_val);
		ft_push(b, a);
	}
}
