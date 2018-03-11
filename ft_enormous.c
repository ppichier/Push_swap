/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_enormous.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/02 19:32:14 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 17:36:23 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_pushswap.h"

static	void	ft_recut_second_split(t_params *p, int count, int s_a)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < count / 2)
	{
		s_a = p->size - *(p->nb_a);
		if (p->tab_a[s_a] < p->med)
		{
			ft_op_pb(p, 1);
			i++;
		}
		else if (i + 1 == count / 2 && p->tab_a[s_a + 1] < p->med)
			ft_op_sa(p, 0, 1);
		else
		{
			ft_op_rotate_a(p, 0, 1);
			j++;
		}
	}
	while (j-- > 0)
		ft_op_reverse_rotate_a(p, 0, 1);
}

void			ft_recut_second(t_params *p, int count)
{
	int s_a;

	s_a = 0;
	if (count <= 2)
	{
		s_a = p->size - *(p->nb_a);
		if (p->tab_a[s_a] > p->tab_a[s_a + 1])
			ft_op_sa(p, 0, 1);
		return ;
	}
	if (ft_portion_is_sort(p, count))
		return ;
	p->med = ft_median_cut(p, count);
	ft_recut_second_split(p, count, s_a);
	if (count % 2 != 0)
		ft_recut_second(p, count / 2 + 1);
	else
		ft_recut_second(p, count / 2);
	ft_recut(p, count / 2);
	if (count % 2 != 0)
		ft_recut_second(p, count / 2 + 1);
	else
		ft_recut_second(p, count / 2);
}

void			ft_recut(t_params *p, int start)
{
	int i;

	i = 0;
	if (start == 1)
	{
		ft_op_pa(p, 1);
		return ;
	}
	while (i < start)
	{
		ft_op_pa(p, 1);
		i++;
	}
}

void			ft_export_pile_a(t_params *p)
{
	int i[3];

	if (*(p->nb_a) <= 2)
	{
		if (!ft_tab_is_sort(p->tab_a, p->size))
			ft_op_sa(p, 0, 1);
		return ;
	}
	i[0] = 0;
	ft_new_median(p);
	i[1] = *(p->nb_a);
	while (i[0] < i[1] / 2)
	{
		i[2] = p->size - *(p->nb_a);
		if (p->tab_a[i[2]] < p->med)
		{
			ft_op_pb(p, 1);
			i[0]++;
		}
		else
			ft_op_rotate_a(p, 0, 1);
	}
	ft_export_pile_a(p);
	ft_recut(p, i[0]);
	ft_recut_second(p, i[0]);
}
