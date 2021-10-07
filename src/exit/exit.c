#include "../header/push_swap.h"

void	ft_exit(int err_nb)
{
	if (err_nb == 1)
		ft_putendl("MEMORY ALLOCATION ERROR");
	else if (err_nb == 2)
		ft_putendl("BAD VALUE ENTERED");
	else if (err_nb == 3)
		ft_putendl("DUPLICATE VALUE FOUND");
	exit(0);
}