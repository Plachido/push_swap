/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:25:30 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/12 20:13:56 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	main(int argc, char **argv)
{
	int *ordered;
	int len;
	t_stack	*a;
	t_stack	*b;

	ordered = ft_char_to_stack(argc, argv, &a);
	ft_duplicates(a);
	b = NULL;
	a = ft_sort(a, b, argc-1);
	//ft_print(a);
	ft_free(a, b);
	free(ordered);
	ft_exit(0);
}
