/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_isorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:21:06 by msoler-e          #+#    #+#             */
/*   Updated: 2022/03/18 12:55:52 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_max(t_stk *a)
{
	int	max;

	max = 0;
	if (a)
	{
		max = a->num;
		while (a)
		{	
			if (max < a->num)
				max = a->num;
			a = a->next;
		}
	}
	return (max);
}

int	ft_min(t_stk *a)
{
	int	min;

	min = 0;
	if (a)
	{
		min = a->num;
		while (a)
		{
			if (min > a->num)
				min = a->num;
			a = a->next;
		}
	}
	return (min);
}

int	ft_order(t_stk *a)
{
	int	ordenat;
	int	ant;

	ordenat = 1;
	if (a)
	{
		ant = a->num;
		a = a->next;
		while (a && ordenat)
		{
			if (ant > a->num)
				ordenat = 0;
			ant = a->num;
			a = a->next;
		}
	}
	return (ordenat);
}
