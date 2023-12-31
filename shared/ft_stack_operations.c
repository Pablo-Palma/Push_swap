/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 09:00:50 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/31 11:43:36 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_init_stack(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
	{
		error_and_free(NULL, NULL, 1, 0);
		return (NULL);
	}
	new_stack->top = NULL;
	return (new_stack);
}

void	ft_push_stack(t_stack *s, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = s->top;
	new_node->previous = NULL;
	if (s->top)
		s->top->previous = new_node;
	s->top = new_node;
}

void	ft_print_stack(t_stack *s)
{
	t_node	*current;

	current = s->top;
	while (current)
	{
		ft_printf("%d ", current->value);
		current = current->next;
	}
	ft_printf("\n");
}

int	ft_stack_len(t_stack *s)
{
	t_node	*current;
	int		count;

	current = s->top;
	count = 0;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	ft_free_stack(t_stack *s)
{
	t_node	*current;
	t_node	*next;

	current = s->top;
	while (current)
	{
		next = current->next;
		free (current);
		current = next;
	}
	free (s);
}
