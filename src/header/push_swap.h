/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:09:39 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/08 12:41:05 by plpelleg         ###   ########.fr       */
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

void	ft_quicksort(int arr[], int low, int high);
t_stack	*ft_r(t_stack *a);
t_stack	*ft_p(t_stack **src, t_stack *des);
t_stack	*ft_bottom(t_stack *elem);
t_stack	*ft_sort(t_stack *a, t_stack *b);
int		ft_stack_size(t_stack *stack);
int		ft_max_bits(t_stack *stack);
void	ft_duplicates(t_stack *stack);
int		ft_atoi_err(const char *str);
void	ft_putstr(char *s);
void	ft_putendl(char *s);
t_stack	*ft_char_to_stack(int len, char **numbers);
t_stack	*ft_top(t_stack *elem);
void	ft_free_stack(t_stack *elem);
void	ft_free(t_stack *a, t_stack *b);
void	ft_exit(int err_nb);
void	ft_print(t_stack *stack); //da rimuovere
#endif
