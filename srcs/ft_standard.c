/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_standard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:54:46 by msoler-e          #+#    #+#             */
/*   Updated: 2022/03/18 12:55:03 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stk	*ft_omplir_stk(t_gstk *resum, t_stk *tmp)
{
	int	i;

	i = 0;
	while (i < resum->size)
	{	
		tmp = ft_lstnewa(resum->simpl[i]);
		ft_lstadd_backa(&resum->a, tmp);
		tmp = NULL;
		i ++;
	}
	return (resum->a);
}

t_gstk	*ft_omplir_simpl(t_gstk *resum, int *temp, int argc)
{
	int	i;
	int	j;

	i = 0;
	resum->simpl = malloc (sizeof(int) * resum->size);
	if (!resum->simpl)
		ft_error("Error Malloc", 0, &resum, argc);
	while (i < resum->size)
	{
		j = 0;
		while (j < resum->size)
		{
			if (temp[i] == resum->numeros[j])
			resum->simpl[j] = i + 1;
			j ++;
		}
		i ++;
	}
	i = 0;
	return (resum);
}

t_gstk	*ft_standard(t_gstk *resum, int argc)
{
	int		*temp;
	int		i;
	t_stk	*stk;

	stk = NULL;
	temp = malloc(sizeof(int) * resum->size);
	if (!temp)
		ft_error("Error Malloc", 0, &resum, argc);
	i = 0;
	while (i < resum->size)
	{
		temp[i] = resum->numeros[i];
		i ++;
	}
	ft_sort_int_tab(temp, resum->size);
	resum = ft_omplir_simpl(resum, temp, argc);
	resum->a = ft_omplir_stk(resum, stk);
	free (temp);
	temp = NULL;
	return (resum);
}
