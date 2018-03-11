/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pile_b.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 14:55:30 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/05 19:50:16 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_pushswap.h"

static	void	ft_place_if_rotate(t_params *p, int indice, int start_b)
{
	int i;
	int k;

	i = 0;
	if (indice - start_b <= p->size - indice)
		k = indice - start_b;
	else
		k = p->size - indice;
	while (i++ < k)
	{
		if (indice - start_b <= p->size - indice)
			ft_op_rotate_b(p, 0, 1);
		else
			ft_op_reverse_rotate_b(p, 0, 1);
	}
	ft_op_pb(p, 1);
	i = (indice - start_b <= p->size - indice) ? 0 : -1;
	while (i++ < k)
	{
		if (indice - start_b <= p->size - indice)
			ft_op_reverse_rotate_b(p, 0, 1);
		else
			ft_op_rotate_b(p, 0, 1);
	}
}

static	void	ft_analyze_place_b(t_params *p)
{
	int indice;
	int start_b;

	start_b = p->size - *(p->nb_b);
	if (ft_indice_insert(p) == -1)
	{
		ft_op_pb(p, 1);
		if (*(p->nb_b) > 1)
			ft_op_rotate_b(p, 0, 1);
	}
	else if (ft_indice_insert(p) == start_b + 1)
	{
		ft_op_pb(p, 1);
		ft_op_sb(p, 0, 1);
	}
	else if (ft_indice_insert(p) != -1)
	{
		indice = ft_indice_insert(p);
		ft_place_if_rotate(p, indice, start_b);
	}
}

static	void	ft_check_push(t_params *p, int s_a)
{
	if (p->tab_a[s_a] < p->tab_a[s_a + 1] &&
			p->tab_a[s_a] < p->tab_a[p->size - 1] && p->tab_a[s_a] < p->med)
		ft_analyze_place_b(p);
	else if (p->tab_a[s_a + 1] < p->tab_a[s_a]
			&& p->tab_a[s_a + 1] < p->tab_a[p->size - 1]
			&& p->tab_a[s_a + 1] < p->med)
	{
		ft_op_sa(p, 0, 1);
		ft_analyze_place_b(p);
	}
	else if (p->tab_a[p->size - 1] < p->tab_a[s_a]
			&& p->tab_a[p->size - 1] < p->tab_a[s_a + 1]
			&& p->tab_a[p->size - 1] < p->med)
	{
		ft_op_reverse_rotate_a(p, 0, 1);
		ft_analyze_place_b(p);
	}
}

void			ft_separate_in_b(t_params *p, int j)
{
	int	i;
	int	s_a;
	int	nb_initial;

	i = 0;
	while (i < j && !(ft_tab_is_sort(p->tab_a, (unsigned int)p->size)))
	{
		nb_initial = *(p->nb_a);
		s_a = p->size - *(p->nb_a);
		ft_check_push(p, s_a);
		if (nb_initial != *(p->nb_a))
			i++;
		else
			ft_rotate_optimal(p, p->med);
	}
}
