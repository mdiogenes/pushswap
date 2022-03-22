/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <mdiogenes@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:12:48 by msoler-e          #+#    #+#             */
/*   Updated: 2022/03/17 09:35:04 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_sort_int_tab(int *tab, int size);
void	quicksort(int *tab, int iesq, int idret);
void	ft_swap(int *a, int *b);

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab( int *tab, int size)
{
	int	iesq;
	int	idret;

	iesq = 0;
	idret = size - 1;
	quicksort(tab, iesq, idret);
}

void	quicksort(int *tab, int iesq, int idret)
{
	int	i;
	int	j;
	int	elem;

	i = iesq;
	j = idret;
	elem = tab[(iesq + idret) / 2];
	while (tab[i] < elem)
		i ++;
	while (elem < tab[j])
		j --;
	if (i <= j)
	{
		ft_swap(&tab[i], &tab[j]);
		i ++;
		j --;
	}
	if (iesq < j)
		quicksort(tab, iesq, j);
	if (i < idret)
		quicksort(tab, i, idret);
}
