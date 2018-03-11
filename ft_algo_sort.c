/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_algo_sort.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <ppichier@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 11:25:17 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/05 20:01:19 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_pushswap.h"

static	void	ft_backb_to_a(t_params *p)
{
	int i;
	int nb;

	i = 0;
	nb = *(p->nb_b);
	if (*(p->nb_b) >= 1)
	{
		while (i < nb)
		{
			ft_op_pa(p, 1);
			i++;
		}
	}
}

void			ft_algo_sort(t_params *p)
{
	ft_calcul_median(p);
	if (ft_cmptab(p->tab_sort, p->tab_a, (unsigned int)p->size))
		return ;
	if (*(p->nb_a) <= 2)
		ft_op_sa(p, 0, 1);
	else if (*(p->nb_a) <= 3)
		ft_sort_little_a(p);
	else if ((*(p->nb_a) <= 50))
	{
		ft_separate_in_b(p, p->size / 2);
		if ((ft_is_sort_rev_tab(p->tab_a, (unsigned int)p->size, *(p->nb_a)))
				&& *(p->nb_a) == 4)
		{
			ft_rev_tab_rotate(p);
		}
		else
			ft_order_a(p);
		ft_backb_to_a(p);
	}
	else if (*(p->nb_a) > 50)
		ft_export_pile_a(p);
}
