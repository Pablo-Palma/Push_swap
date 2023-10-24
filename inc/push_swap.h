/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:26:56 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/23 23:05:41 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>

//stack and node list
typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	char	identifier;
}	t_stack;

//chunks_and_hold structs
typedef struct s_chunk_limits
{
	int	min;
	int	max;
}	t_chunk_limits;

typedef struct s_hold
{
	int	value;
	int	pos;
}	t_hold;

//push_swap functions
void	ft_push_swap(int argc, char **argv);

//check_input functions
int		has_duplicates(int *numbers, int size);
int		is_valid_input(int argc, char **argv);
int		*ft_parse_input(int argc, char **argv);

//push_swap functions
void	ft_sort_three_numbers(t_stack *s);
void	ft_sort_five_numbers(t_stack *a, t_stack *b);
void	ft_sort_hundred(t_stack *a, t_stack *b, int chunk_count);

//stack_pos functions
int		ft_find_position(t_stack *s, int number);
int		ft_is_value_in_chunk(t_stack *s, int chunk_min, int chunk_max);
int		ft_find_extreme_value(t_stack *s, char *type,
							int limits_min, int limits_max);
int		find_first_hold(t_stack *a, t_chunk_limits limits);
int		find_second_hold(t_stack *a, t_chunk_limits limits);
void	ft_move_number_to_top(t_stack *s, int number);

//stack_init functions
t_stack	*ft_init_stack(void);
void	ft_push_stack(t_stack *s, int value);
void	ft_print_stack(t_stack *s);
int		ft_stack_len(t_stack *s);
void	ft_free_stack(t_stack *s);

//stack_operations functions
void	ft_swap(t_stack *s);
void	ft_push(t_stack *src, t_stack *dst);
void	ft_rotate(t_stack *s);
void	ft_reverse_rotate(t_stack *s);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_rr(t_stack *a, t_stack *b);
void	ft_rrr(t_stack *a, t_stack *b);

#endif
