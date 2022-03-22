/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 09:40:10 by msoler-e          #+#    #+#             */
/*   Updated: 2022/03/18 14:07:54 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_conuntilmin(t_stk *a)
{
	int	contador;

	contador = 0;
	while (a->num != ft_min(a))
	{
		contador = contador + 1;
		a = a->next;
	}
	return (contador);
}

t_stk	*ft_petit_dreta(t_stk *a, int size)
{
	int		cont;

	cont = ft_conuntilmin(a);
	if (cont >= size / 2)
	{
		while (size - cont > 0)
		{	
			a = ft_rra(a);
			cont ++;
		}
	}
	else
	{
		while (cont > 0)
		{
			a = ft_ra(a);
			cont --;
		}
	}
	return (a);
}

void	ft_sort5(t_stk **a, t_stk **b, t_gstk *resum)
{
	int	size;

	size = resum->size;
	*a = ft_petit_dreta(*a, size);
	ft_pb(&(*a), &(*b));
	size = size - 1;
	*a = ft_petit_dreta(*a, size);
	ft_pb(&(*a), &(*b));
	*a = ft_3order(*a, *b);
	ft_pa(&(*a), &(*b));
	ft_pa(&(*a), &(*b));
	size = size +1;
}

void	ft_short_sort(t_stk **a, t_stk **b, t_gstk *resum)
{
	int	size;

	size = resum->size;
	if (*a)
	{
		if (size == 2)
		{
			*a = ft_ra(*a);
		}
		if (size == 3)
		{
			*a = ft_3order(*a, *b);
		}
		if (size == 4)
		{
			*a = ft_petit_dreta(*a, size);
			ft_pb(&(*a), &(*b));
			*a = ft_3order(*a, *b);
			ft_pa(&(*a), &(*b));
		}
		if (size == 5)
			ft_sort5(a, b, resum);
	}
}
