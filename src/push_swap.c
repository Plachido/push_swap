/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:25:30 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/14 15:52:39 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc > 1)
	{
		a = ft_char_to_stack(argc, argv);
		ft_duplicates(a);
		b = NULL;
		if (argc <= 6)
			a = ft_sort_small(a, b, argc-1);
		a = ft_sort(a, b, argc-1);
		ft_free(a, b);
		ft_exit(0);
	}
}