/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:19:40 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/14 11:39:48 by pabpalma         ###   ########.fr       */
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

	while (ft_stack_len(a) > 3)
	{
		smallest = find_smallest(a);
		while (a->top->value != smallest)
			ft_rotate(a);
		ft_push(a, b);
	}
	ft_sort_three_numbers(a);
	while (b->top)
		ft_push(b, a);
}
