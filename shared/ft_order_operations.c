/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:54:11 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/28 22:48:41 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s)
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
}

void	ft_swap(t_stack *s, int print)
{
	int	temp;

	if (!s || !s->top || !s->top->next)
		return ;
	temp = s->top->value;
	s->top->value = s->top->next->value;
	s->top->next->value = temp;
	if (print)
		ft_printf("s%c\n", s->identifier);
}

void	ft_push(t_stack *src, t_stack *dst, int print)
{
	t_node	*temp;

	if (!src || !src->top)
		return ;
	temp = src->top;
	src->top = src->top->next;
	temp->next = dst->top;
	dst->top = temp;
	if (print)
		ft_printf("p%c\n", dst->identifier);
}

void	ft_rotate(t_stack *s, int print)
{
	t_node	*temp;
	t_node	*current;

	if (!s || !s->top || !s->top->next)
		return ;
	temp = s->top;
	s->top = s->top->next;
	current = s->top;
	while (current->next)
		current = current->next;
	current->next = temp;
	temp->next = NULL;
	if (print)
		ft_printf("r%c\n", s->identifier);
}

void	ft_reverse_rotate(t_stack *s, int print)
{
	t_node	*prev;
	t_node	*current;

	if (!s || !s->top || !s->top->next)
		return ;
	prev = NULL;
	current = s->top;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = s->top;
	s->top = current;
	if (print)
		ft_printf("rr%c\n", s->identifier);
}
