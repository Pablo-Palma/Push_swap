/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:46:20 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/24 13:13:15 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (len <= 500)
	{
		ft_sort_hundred(a, b, 11);
	}
}

void	ft_push_swap(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*numbers;
	int		i;

	a = ft_init_stack();
	b = ft_init_stack();
	a->identifier = 'a';
	b->identifier = 'b';
	numbers = ft_parse_input(argc, argv);
	i = argc -2;
	while (i >= 0)
	{
		ft_push_stack(a, numbers[i]);
		i--;
	}
//	printf("Pila A antes de ordenar:\n");
//	ft_print_stack(a);
	free(numbers);
	ft_sort_sizebased(a, b);
//	printf("Pila A ordenada: \n");
//	ft_print_stack(a);
	ft_free_stack(a);
	ft_free_stack(b);
}

/*int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	ft_push_swap(argc, argv);
	return (0);
}*/
