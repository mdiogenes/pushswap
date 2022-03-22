/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:39:10 by msoler-e          #+#    #+#             */
/*   Updated: 2022/03/18 14:07:52 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_free_stk(t_stk **stk)
{
	t_stk	*temp;

	if (*stk)
	{
		temp = *stk;
		while (temp != NULL)
		{	
			*stk = temp;
			temp = temp->next;
			ft_delone(stk);
		}
		ft_delone(&temp);
		*stk = NULL;
	}
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			free (split[i]);
		i++;
		}
		split = NULL;
	}
}

void	ft_free(t_gstk **resum, int argc)
{
	if ((*resum)->numeros)
		free((*resum)->numeros);
	if ((*resum)->simpl)
		free((*resum)->simpl);
	if (argc == 2 && (*resum)->split)
		ft_free_split((*resum)->split);
	(*resum)->numeros = NULL;
	(*resum)->simpl = NULL;
	ft_free_stk(&(*resum)->a);
	ft_free_stk(&(*resum)->b);
	if (*resum)
		free (*resum);
	*resum = NULL;
}

void	push_swap(t_gstk *resum, int argc, char *argv[])
{
	resum = ft_omplir_argv(resum, argc, argv);
	ft_check_isnum(resum->split, &resum, argc);
	ft_check_dup(resum, argc);
	resum = ft_standard(resum, argc);
	resum->b = NULL;
	if (resum->size <= 5 && !ft_order(resum->a))
		ft_short_sort(&resum->a, &resum->b, resum);
	if (resum->size > 5 && !ft_order(resum->a))
		ft_long_sort(&resum->a, &resum->b, resum->size);
	ft_free(&resum, argc);
}
