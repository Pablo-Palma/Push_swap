/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:57:24 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/25 12:48:43 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_and_rotate(t_stack *s, int a, int b, int c)
{
	if (a < b && b < c)
		return ;
	else if (a < b && b > c && a < c) 
	{
		ft_swap(s);
		ft_rotate(s);
	}
	else if (a > b && b < c && a < c)
		ft_swap(s);
	else if (a < b && b > c && a > c)
		ft_reverse_rotate(s);
	else if (a > b && b < c && a > c)
		ft_rotate(s);
	else
	{
		ft_rotate(s);
		ft_swap(s);
	}
}

void	ft_sort_three_numbers(t_stack *s)
{
	int	a;
	int	b;
	int	c;

	if (!s || !s->top || !s->top->next || !s->top->next->next)
		return ;
	a = s->top->value;
	b = s->top->next->value;
	c = s->top->next->next->value;
	sort_and_rotate(s, a, b, c);
}
