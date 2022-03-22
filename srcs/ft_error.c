/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:59:19 by msoler-e          #+#    #+#             */
/*   Updated: 2022/03/18 11:05:53 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *cnt, int error, t_gstk **resum, int argc)
{
	if (error == 2)
		ft_putstr_fd(cnt, 1);
	if (error == 0)
		ft_putstr_fd(cnt, 1);
	if (error == 1)
		ft_putstr_fd(cnt, 1);
	ft_free(resum, argc);
	exit (error);
}
