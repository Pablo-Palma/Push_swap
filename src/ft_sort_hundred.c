/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hundred.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:23:57 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/24 12:08:36 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int ft_find_next_max(t_stack *b, int max_val)
{
    t_node *current = b->top;
    int next_largest = INT_MIN;
    int found_larger = 0;

    while (current != NULL) {
        if (current->value < max_val && current->value > next_largest) {
            next_largest = current->value;
            found_larger = 1;
        } 
        if (current->value > max_val) {
            found_larger = 0;
        }
        current = current->next;
    }

    if (found_larger) {
        return next_largest;
    } else {
        return -1;
    }
}*/

/*void push_back_in_order(t_stack *a, t_stack *b)
{
    while (b->top)
    {
        if (smart_rotate_b(b, a))
        {
            if (b->top && b->top->next && a->top && a->top->next &&
                b->top->value < b->top->next->value &&
                a->top->value > a->top->next->value)
            {
                ft_ss(a, b);
            }
            else if (a->top && a->top->value > b->top->value)
            {
                ft_swap(a);
            }
            ft_push(b, a);
        }
        else
            ft_push(b, a);
    }
}*/

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

int try_push_next(t_stack *b, t_stack *a, int swap)
{
    int value;
	int	max_val;

    if (!b->top || !b->top->next)
        return (0);
    value = b->top->value;
	max_val = ft_find_extreme_value(b, "max", INT_MIN, INT_MAX);
    if (value == max_val -1  && !swap)
    {
        ft_push(b, a);
        return (1);
    }
    return (0);
}

int smart_rotate_b(t_stack *b, t_stack *a)
{
    int count;
    int swap;
    int size;
    int max_val;

    swap = 0;
    size = ft_stack_len(b);
    max_val = ft_find_extreme_value(b, "max", INT_MIN, INT_MAX);
    count = ft_find_position(b, max_val);
    while (b->top && b->top->value != max_val)
    {
        if (!try_push_next(b, a, swap))
        {
            if (count > size / 2)
                ft_reverse_rotate(b);
            else
               ft_rotate(b);
        }
        else
            swap = 1;
    }
    return (swap);
}

void push_back_in_order(t_stack *a, t_stack *b)
{
    while (b->top)
    {
        if (smart_rotate_b(b, a))
        {
			ft_push(b, a);
            if (a->top && a->top->value > a->top->next->value)
			{
				if (b->top && b->top->next && b->top->value < b->top->next->value)
					ft_ss(a,b);
                else
					ft_swap(a);
			}
        }
        else
            ft_push(b, a);
    }
}

void	handle_chunk(t_stack *a, t_stack *b, t_chunk_limits limits)
{
	int	hold_first;
	int	hold_second;
	int	pos_first;
	int	pos_second;
	int	chunk_size = limits.max - limits.min + 1;
	int	chunk_half = chunk_size / 2;

	while (ft_is_value_in_chunk(a, limits.min, limits.max))
	{
		hold_first = find_first_hold(a, limits);
		hold_second = find_second_hold(a, limits);
		pos_first = ft_find_position(a, hold_first);
		pos_second = ft_stack_len(a) - ft_find_position(a, hold_second);
		if (pos_first < pos_second)
			ft_move_number_to_top(a, hold_first);
		else
			ft_move_number_to_top(a, hold_second);
		ft_push(a, b);
		if(b->top  && b->top->value < limits.min + chunk_half)
		{
			hold_first = find_first_hold(a, limits);
			hold_second = find_second_hold(a, limits);
			pos_first = ft_find_position(a, hold_first);
			pos_second = ft_stack_len(a) - ft_find_position(a, hold_second);
			if (pos_first < pos_second)
				ft_rr(a, b);
			else
				ft_rotate(b);
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
//	chunk_size = (total_max - total_min) / chunk_count;
	chunk_size = ft_stack_len(a) / 12 + 22;
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
	max_val = ft_find_extreme_value(b, "max", INT_MIN, INT_MAX);
	ft_move_number_to_top(b, max_val);
//	printf("\n");
	push_back_in_order(a, b);
}
