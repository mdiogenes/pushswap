/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 09:04:25 by msoler-e          #+#    #+#             */
/*   Updated: 2022/03/18 10:16:23 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stk	*ft_lstnewa(int content)
{
	t_stk	*newone;

	newone = malloc(sizeof(t_stk));
	if (!newone)
		return (0);
	newone->num = content;
	newone->next = NULL;
	newone->prev = NULL;
	return (newone);
}

void	ft_lstadd_backa(t_stk **lst, t_stk *newa)
{
	t_stk	*last;
	t_stk	*temp;

	last = *lst;
	temp = *lst;
	if (newa)
	{
		if (*lst)
		{
			while (last->next)
			{
				temp = last;
				last = last->next;
			}			
			last->next = newa;
			last->prev = last;
		}
		else
			*lst = newa;
	}
}

t_stk	*ft_lstadd_fronta(t_stk *lst, t_stk *newa)
{
	if (newa)
	{
		if (lst)
		{
			newa->next = lst;
			lst = newa;
		}
		else
			lst = newa;
	}
	return (lst);
}

void	ft_delone(t_stk **lst)
{
	t_stk	*temp;

	if (*lst)
	{
		temp = *lst;
		if ((*lst)->next)
		{	
			(*lst)->num = (int) NULL;
			*lst = (*lst)->next;
			free (temp);
			temp = NULL;
		}
		else
		{
			(*lst)->num = (int) NULL;
			free (*lst);
			*lst = NULL;
		}	
	}
}
