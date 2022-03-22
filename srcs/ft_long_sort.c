/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:32:12 by msoler-e          #+#    #+#             */
/*   Updated: 2022/03/18 11:28:17 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_numbits(t_stk **a)
{
	int	numbits;

	numbits = 0;
	while ((ft_max(*a) >> numbits) != 0)
		numbits ++;
	return (numbits);
}

void	ft_buidarb(t_stk **a, t_stk **b)
{
	if (*b)
	{
		while ((*b)->next)
			ft_pa(a, b);
		ft_pa(a, b);
	}
}

void	ft_long_sort(t_stk **a, t_stk **b, int sizea)
{
	int		max_bits;
	int		i;
	int		j;
	int		num;

	num = 0;
	max_bits = ft_numbits(a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < sizea && !(ft_order(*a)))
		{	
			num = (*a)->num;
			if (((num >> i) & 1) == 0)
				ft_pb(&(*a), &(*b));
			else
				*a = ft_ra(*a);
			j ++;
		}
		ft_buidarb(a, b);
		i ++;
	}
}
