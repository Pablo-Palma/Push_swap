/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:57:24 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/15 08:48:32 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (a < b && b < c)
		return ;
	else if (a < b && b > c && a < c) // 1 3 2
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
/*
int	main(int argc, char **argv)
{
	t_stack s;

	s.top = NULL;
	if (argc != 4)
	{
		fprintf(stderr, "Uso: %s num1 num2 num3\n", argv[0]);
		return (1);
	}
	ft_push_stack(&s, atoi(argv[3]));
	ft_push_stack(&s, atoi(argv[2]));
	ft_push_stack(&s, atoi(argv[1]));
	printf("El stack inicializa en: ");
	ft_print_stack(&s);
	printf("acciones: \n");
	ft_sort_three_numbers(&s);
	printf("El stack ordenado: ");
	ft_print_stack(&s);
	return (0);
}*/
