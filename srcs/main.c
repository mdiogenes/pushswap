/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:10:28 by msoler-e          #+#    #+#             */
/*   Updated: 2022/03/18 11:09:23 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_gstk	*resum;

	resum = malloc(sizeof(t_gstk));
	if (!resum)
		ft_error("Error Malloc", 0, &resum, argc);
	if (argc < 2)
		ft_error("", 2, &resum, argc);
	push_swap(resum, argc, argv);
}
