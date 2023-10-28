/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order2_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:22:34 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/28 22:49:29 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_stack *a, t_stack *b, int print)
{
	ft_swap(a, 0);
	ft_swap(b, 0);
	if (print)
		ft_printf("ss\n");
}

void	ft_rr(t_stack *a, t_stack *b, int print)
{
	ft_rotate(a, 0);
	ft_rotate(b, 0);
	if (print)
		ft_printf("rr\n");
}
