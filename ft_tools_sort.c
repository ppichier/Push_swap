/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tools_sort.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 16:18:30 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/27 19:34:31 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_calcul_median(t_params *p)
{
	int	i;

	i = 0;
	p->tab_sort = ft_tabcpy_int((p->tab_a), p->size);
	ft_sort_int_notcast_tab(p->tab_sort, (unsigned int)p->size);
	p->med = p->tab_sort[p->size / 2];
}

void	ft_rev_tab_rotate(t_params *p)
{
	ft_op_sa(p, 0, 1);
	ft_op_reverse_rotate_a(p, 0, 1);
	ft_op_reverse_rotate_a(p, 0, 1);
	ft_op_sa(p, 0, 1);
}

int		ft_next_minus_median(t_params *p, int vc, int *tab, int k)
{
	int	i;
	int	j;
	int	start_a;
	int	cpt1;
	int	cpt2;

	cpt1 = 0;
	cpt2 = 0;
	start_a = p->size - *(p->nb_a);
	i = start_a + k;
	j = p->size - 1;
	while (tab[i] >= vc && i < p->size)
	{
		cpt1++;
		i++;
	}
	while (tab[j] >= vc && j >= 0)
	{
		cpt2++;
		j--;
	}
	if (cpt1 < cpt2)
		return (1);
	else
		return (0);
}

void	ft_rotate_optimal(t_params *p, int value_cmp)
{
	if (ft_next_minus_median(p, value_cmp, p->tab_a, 1) == 1)
		ft_op_rotate_a(p, 0, 1);
	else
		ft_op_reverse_rotate_a(p, 0, 1);
}

int		ft_indice_insert(t_params *p)
{
	int	start_a;
	int	start_b;

	start_a = p->size - *(p->nb_a);
	start_b = p->size - *(p->nb_b);
	while (start_b < p->size)
	{
		if (p->tab_a[start_a] > p->tab_b[start_b])
			return (start_b);
		start_b++;
	}
	return (-1);
}
