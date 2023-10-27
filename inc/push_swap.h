/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:26:56 by pabpalma          #+#    #+#             */
/*   Updated: 2023/10/27 17:39:24 by pabpalma         ###   ########.fr       */
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
	int	total_min;
	int	total_max;
}	t_chunk_limits;

//push_swap functions
void	ft_push_swap(int argc, int **numbers);
int		is_sorted(t_stack *s);
int		ft_countin_chunk(t_stack *a, t_chunk_limits limits, int chunk_half);

//check_input functions
int		has_duplicates(int *numbers, int size);
int		is_valid_input(int argc, char **argv);
int		*ft_parse_input(int argc, char **argv);
int		one_argument_eval(char *str, char ***new_argv, int *new_argc);
void	free_array(char **array);
int		error_and_free(char **argv, int *numbers, int error_code);

//push_swap functions
void	ft_sort_three_numbers(t_stack *s);
void	ft_sort_five_numbers(t_stack *a, t_stack *b);
void	ft_sort_hundred(t_stack *a, t_stack *b, int chunk_count);

//stack_pos functions
int		ft_find_position(t_stack *s, int number);
int		ft_is_value_in_chunk(t_stack *s, int chunk_min, int chunk_max);
int		ft_find_extreme_value(t_stack *s, char *type,
			int limits_min, int limits_max);
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
void	ft_swap_silent(t_stack *s);
void	ft_rotate_silent(t_stack *s);
void	ft_reverse_rotate_silent(t_stack *s);
void	ft_push_silent(t_stack *src, t_stack *dst);
#endif
