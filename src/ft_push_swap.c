/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:46:20 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/27 17:00:01 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	is_sorted(t_stack *s)
{
	t_node	*current;

	if (!s || !s->top)
		return (1);
	current = s->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}*/

void	ft_sort_sizebased(t_stack *a, t_stack *b)
{
	int	len;

	len = ft_stack_len(a);
	if (len == 2 && (a->top->value > a->top->next->value))
	{
		ft_swap(a);
		return ;
	}
	if (len <= 3)
	{
		ft_sort_three_numbers(a);
		return ;
	}
	if (len <= 5)
	{
		ft_sort_five_numbers(a, b);
		return ;
	}
	if (len <= 100)
	{
		ft_sort_hundred(a, b, 5);
		return ;
	}
	if (len > 5)
		ft_sort_hundred(a, b, 11);
}

void	ft_push_swap(int argc, int **p_numbers)
{
	t_stack	*a;
	t_stack	*b;
	int		*numbers;
	int		i;

	a = ft_init_stack();
	b = ft_init_stack();
	a->identifier = 'a';
	b->identifier = 'b';
	numbers = *p_numbers;
	i = argc - 2;
	while (i >= 0)
	{
		ft_push_stack(a, numbers[i]);
		i--;
	}
	free(numbers);
	if (ft_stack_len(a) >= 2 && !is_sorted(a))
		ft_sort_sizebased(a, b);
	ft_free_stack(a);
	ft_free_stack(b);
}
