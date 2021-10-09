/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:25:30 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/08 12:41:18 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = ft_char_to_stack(argc, argv);
	ft_duplicates(a);
	b = NULL;
	a = ft_sort(a, b);
	//ft_print(a);
	ft_free(a, b);
	ft_exit(0);
}
