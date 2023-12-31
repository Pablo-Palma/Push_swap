/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hundred.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:23:57 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/30 12:18:07 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	try_push_next(t_stack *b, t_stack *a, int swap)
{
	int	value;
	int	max_val;

	if (!b->top || !b->top->next)
		return (0);
	value = b->top->value;
	max_val = ft_find_extreme_value(b, "max", INT_MIN, INT_MAX);
	if (value == max_val -1 && !swap)
	{
		ft_push(b, a, 1);
		return (1);
	}
	return (0);
}

int	smart_rotate_b(t_stack *b, t_stack *a)
{
	int	count;
	int	swap;
	int	size;
	int	max_val;

	swap = 0;
	size = ft_stack_len(b);
	max_val = ft_find_extreme_value(b, "max", INT_MIN, INT_MAX);
	count = ft_find_position(b, max_val);
	while (b->top && b->top->value != max_val)
	{
		if (!try_push_next(b, a, swap))
		{
			if (count > size / 2)
				ft_reverse_rotate(b, 1);
			else
				ft_rotate(b, 1);
		}
		else
			swap = 1;
	}
	return (swap);
}

void	push_back_in_order(t_stack *a, t_stack *b)
{
	while (b->top)
	{
		if (smart_rotate_b(b, a))
		{
			ft_push(b, a, 1);
			if (a->top && a->top->value > a->top->next->value)
			{
				if (b->top && b->top->next && b->top->value
					< b->top->next->value)
					ft_ss(a, b, 1);
				else
					ft_swap(a, 1);
			}
		}
		else
			ft_push(b, a, 1);
	}
}

void	handle_chunk(t_stack *a, t_stack *b, t_chunk_limits limits)
{
	int	chunk_size;
	int	chunk_half;

	chunk_size = limits.max - limits.min + 1;
	chunk_half = chunk_size / 2;
	while (ft_is_value_in_chunk(a, limits.min, limits.max))
	{
		if (a->top->value >= limits.min && a->top->value <= limits.max)
		{
			ft_push(a, b, 1);
			if (b->top && b->top->value < limits.min + chunk_half)
			{
				if (a->top && !ft_is_value_in_chunk(a, limits.min, limits.max))
					ft_rr(a, b, 1);
				else
					ft_rotate(b, 1);
			}
		}
		else if (!ft_countin_chunk(a, limits, chunk_half))
			ft_reverse_rotate(a, 1);
		else
			ft_rotate(a, 1);
	}
}

void	ft_sort_hundred(t_stack *a, t_stack *b, int chunk_count)
{
	int				i;
	int				chunk_size;
	t_chunk_limits	limits;

	i = 0;
	limits.total_min = ft_find_extreme_value(a, "min", INT_MIN, INT_MAX);
	limits.total_max = ft_find_extreme_value(a, "max", INT_MIN, INT_MAX);
	chunk_size = ft_stack_len(a) / 12 + 22;
	while (i < chunk_count)
	{
		limits.min = limits.total_min + (i * chunk_size);
		if (i == chunk_count - 1)
			limits.max = limits.total_max;
		else
			limits.max = limits.min + chunk_size;
		handle_chunk(a, b, limits);
		i++;
	}
	push_back_in_order(a, b);
}
