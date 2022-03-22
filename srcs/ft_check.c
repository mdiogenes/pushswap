/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_isint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:40:58 by msoler-e          #+#    #+#             */
/*   Updated: 2022/03/18 11:08:08 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_check_isint(long int num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

void	ft_check_dup(t_gstk *resum, int argc)
{
	int	i;
	int	j;
	int	duplicat;

	i = 0;
	while (i < resum->size)
	{
		j = 0;
		duplicat = 0;
		while (j < resum->size)
		{
			if (resum->numeros[i] == resum->numeros[j])
			{
				duplicat = duplicat + 1;
				if (duplicat == 2)
					ft_error("error_duplicat", 1, &resum, argc);
			}
			j++;
		}
		i ++;
	}
}

void	ft_check_isnum(char **num, t_gstk **resum, int argc)
{
	int		i;
	int		j;

	i = 0;
	while (num[i])
	{
		j = 0;
		while (num[i][j])
		{
			if (ft_isalpha(num[i][j]) == 1 || num[i][j] == '.'
			|| ((num[i][j]) == '-' && (num[i][j +1]) == '\0')
			|| ((num[i][j]) == '+' && (num[i][j +1]) == '\0'))
				ft_error("error_no es un numero", 1, resum, argc);
			j ++;
		}
		i ++;
	}
}
