/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:19:40 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/28 14:12:22 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_stack *s)
{
	t_node	*current;
	int		min_val;

	if (!s || !s->top)
		return (-1);
	current = s->top;
	min_val = current->value;
	while (current)
	{
		if (current->value < min_val)
			min_val = current->value;
		current = current->next;
	}
	return (min_val);
}

void	ft_sort_five_numbers(t_stack *a, t_stack *b)
{
	int	smallest;
	int	pos;
	int	len;

	while (ft_stack_len(a) > 3)
	{
		smallest = find_smallest(a);
		pos = ft_find_position(a, smallest);
		len = ft_stack_len(a);
		if (pos > len / 2)
		{
			while (a->top->value != smallest)
				ft_reverse_rotate(a, 1);
		}
		else
		{
			while (a->top->value != smallest)
				ft_rotate(a, 1);
		}
		ft_push(a, b, 1);
	}
	ft_sort_three_numbers(a);
	while (b->top)
		ft_push(b, a, 1);
}
