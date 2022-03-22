/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3order.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 09:41:06 by msoler-e          #+#    #+#             */
/*   Updated: 2022/03/18 15:13:38 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_pb(t_stk **a, t_stk **b)
{
	t_stk	*temp;

	ft_putstr_fd("pb\n", 1);
	if (*a)
	{
		temp = ft_lstnewa((*a)->num);
		*b = ft_lstadd_fronta((*b), temp);
		ft_delone(a);
	}
}

void	ft_pa(t_stk **a, t_stk **b)
{
	t_stk	*temp;

	ft_putstr_fd("pa\n", 1);
	if (*b)
	{
		temp = ft_lstnewa((*b)->num);
		*a = ft_lstadd_fronta((*a), temp);
		ft_delone(b);
	}
}

t_stk	*ft_rra(t_stk *a)
{
	t_stk	*temp;
	t_stk	*b;

	ft_putstr_fd("rra\n", 1);
	if (a)
	{
		b = a;
		temp = a;
		a = a->next;
		while (a->next)
		{
			temp = a;
			a = a->next;
		}
		a->next = b;
		temp->next = NULL;
	}
	return (a);
}

t_stk	*ft_ra(t_stk *a)
{
	t_stk	*inici;
	t_stk	*b;

	inici = NULL;
	ft_putstr_fd("ra\n", 1);
	if (a)
	{
		b = a;
		a = a->next;
		b->next = NULL;
		inici = a;
		while (a->next)
			a = a->next;
		a->next = b;
	}
	return (inici);
}

t_stk	*ft_especial_sa(t_stk *inici)
{
	t_stk	*temp;
	t_stk	*a;
	int		primer;
	a = inici;
	temp = a;
	if (inici)
	{
		if (a->num == 3)
			inici = ft_ra(inici);
		if (a->num == 2)
		{
			primer = a->num;
			a = a->next;
			temp = a->next;
			inici->next = temp;
			a = inici;
		   ft_putstr_fd("sa\n", 1);	
		}

	}
	return (inici);
}

t_stk	*ft_3order(t_stk *a, t_stk *b)
{
	t_stk	*inici;
	int		cont;

	inici = a;
	cont = 0;
	while (a && a->num != ft_min(inici))
	{
		cont = cont + 1;
		a = a->next;
	}
	if (cont == 1)
		inici=ft_especial_sa(inici);
	if (cont == 2)
		inici = ft_rra(inici);
	if (ft_order(inici))
		return (inici);
	else
	{
		ft_pb(&inici, &b);
		inici = ft_ra(inici);
		ft_pa(&inici, &b);
		return (inici);
	}
	return (0);
}
