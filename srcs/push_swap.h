/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:58:51 by msoler-e          #+#    #+#             */
/*   Updated: 2022/03/18 12:53:16 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>	
# include <limits.h>

typedef struct s_var
{
	int				num;
	struct s_var	*next;
	struct s_var	*prev;
}	t_stk;

typedef struct s_stk
{
	char	**split;
	int		*numeros;
	int		*simpl;
	int		size;
	t_stk	*a;
	t_stk	*b;
}	t_gstk;
void	ft_free(t_gstk **resum, int argc);
void	ft_delone(t_stk **lst);
void	ft_pa(t_stk **a, t_stk **b);
void	ft_pb(t_stk **a, t_stk **b);
t_stk	*ft_3order(t_stk *a, t_stk *b);
int		ft_order(t_stk *a);
int		ft_min(t_stk *a);
int		ft_max(t_stk *a);
t_stk	*ft_rra(t_stk *a);
t_stk	*ft_ra(t_stk *a);
void	ft_short_sort(t_stk **a, t_stk **b, t_gstk *resum);
void	ft_long_sort(t_stk **a, t_stk **b, int size);
int		ft_check_isorder(t_stk *a);
void	ft_sort_int_tab(int *tab, int size);
t_gstk	*ft_standard(t_gstk *resum, int argc);
int		ft_check_isint(long int num);
void	ft_check_isnum(char **num, t_gstk **resum, int argc);
void	ft_check_dup(t_gstk *resum, int argc);
t_gstk	*ft_omplir_argv(t_gstk *resum, int argc, char *argv[]);
void	ft_error(char *cnt, int error, t_gstk **resum, int argc);
void	push_swap(t_gstk *resum, int argc, char *argv[]);
void	ft_lstadd_backa(t_stk **lst, t_stk *newa);
t_stk	*ft_lstadd_fronta(t_stk *lst, t_stk *newa);
t_stk	*ft_lstnewa(int content);

#endif
