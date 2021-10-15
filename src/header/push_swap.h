/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:09:39 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/15 12:17:32 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../../libft/libft.h"

typedef struct s_stack
{
	int					num;
	struct s_stack		*prev;
	struct s_stack		*next;
}				t_stack;

//exit.c
void	ft_exit(int err_nb);
//free.c
void	ft_free_stack(t_stack *elem);
void	ft_malloc_error(int numbers[], t_stack *stack);
void	ft_free(t_stack *a, t_stack *b);
//fix_ordered.c
int		ft_stack_ordered(t_stack *a, int len);
//small.c
t_stack	*ft_sort_small(t_stack *a, t_stack *b, int len);
//sort.c
void	ft_choose_rotation(t_stack **a, int num, int len, int index);
void	ft_push_back(t_stack **a, t_stack **b, int size);
t_stack	*ft_sort(t_stack *a, t_stack *b, int len);
//push.c
t_stack	*ft_p(t_stack **src, t_stack *des);
//rotate.c
t_stack	*ft_r(t_stack *a);
t_stack	*ft_rr(t_stack *a);
//switch.c
t_stack	*ft_s(t_stack *stack);
//stack.c
t_stack	*ft_char_to_stack(int len, char **numbers);
//top_bottom.c
t_stack	*ft_top(t_stack *elem);
t_stack	*ft_bottom(t_stack *elem);
//atoi_ps.c
void	ft_atoi_ps(t_stack *stack, int *values, int index, const char *str);
//duplicates.c
void	ft_duplicates(t_stack *stack);
//quicksort.c
void	ft_quicksort(int arr[], int low, int high);
//utils.c
int		ft_max_bits(t_stack *stack);
int		ft_stack_size(t_stack *stack);
int		ft_min(t_stack *a);
#endif
