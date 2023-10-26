/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:54:11 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/25 23:53:30 by pabpalma         ###   ########.fr       */
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

void	ft_swap(t_stack *s)
{
	int	temp;

	if (!s || !s->top || !s->top->next)
		return ;
	temp = s->top->value;
	s->top->value = s->top->next->value;
	s->top->next->value = temp;
	printf("s%c\n", s->identifier);
}

void	ft_push(t_stack *src, t_stack *dst)
{
	t_node	*temp;

	if (!src || !src->top)
		return ;
	temp = src->top;
	src->top = src->top->next;
	temp->next = dst->top;
	dst->top = temp;
	printf("p%c\n", dst->identifier);
}

void	ft_rotate(t_stack *s)
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
	printf("r%c\n", s->identifier);
}

void	ft_reverse_rotate(t_stack *s)
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
	printf("rr%c\n", s->identifier);
}
