/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order2_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:22:34 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/27 00:06:21 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_silent(t_stack *s)
{
	int	temp;

	if (!s || !s->top || !s->top->next)
		return ;
	temp = s->top->value;
	s->top->value = s->top->next->value;
	s->top->next->value = temp;
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_swap_silent(a);
	ft_swap_silent(b);
	printf("ss\n");
}

void	ft_rotate_silent(t_stack *s)
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
}

void	ft_reverse_rotate_silent(t_stack *s)
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
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_rotate_silent(a);
	ft_rotate_silent(b);
	printf("rr\n");
}
