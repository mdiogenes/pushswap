/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_omplir_argv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:22:32 by msoler-e          #+#    #+#             */
/*   Updated: 2022/03/18 12:54:33 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_gstk	*ft_omplir_argv(t_gstk *resum, int argc, char *argv[])
{
	int	i;
	int	size;

	if (argc == 2)
		resum->split = ft_split(argv[1], ' ');
	else
		resum->split = &argv[1];
	i = 0;
	while (resum->split[i])
		i ++;
	size = i;
	resum->numeros = malloc (sizeof(int) * size);
	if (!resum->numeros)
		ft_error("Error Malloc", 0, &resum, argc);
	i = 0;
	while (resum->split[i])
	{
		if (!ft_check_isint(ft_atoi((const char *)resum->split[i])))
			ft_error("max/min INT sobrepassat", 1, &resum, argc);
		resum->numeros[i] = ft_atoi((const char *)resum->split[i]);
		i ++;
	}
	resum->size = i;
	return (resum);
}
