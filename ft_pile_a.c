/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pile_a.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/21 16:27:34 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/05 19:49:03 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_sort_big_a(t_params *p)
{
	int		i;
	int		*tmp;
	int		s_a;
	int		nb;

	while (*(p->nb_a) > 3 && !(ft_tab_is_sort(p->tab_a, (unsigned int)p->size)))
	{
		if (!(tmp = (int*)malloc(sizeof(*tmp) * (*(p->nb_a)))))
			return ;
		s_a = p->size - *(p->nb_a);
		i = 0;
		while (s_a < p->size)
		{
			tmp[i] = p->tab_a[s_a];
			i++;
			s_a++;
		}
		ft_sort_int_notcast_tab(tmp, (unsigned int)*(p->nb_a));
		nb = tmp[*(p->nb_a) / 2];
		p->med = nb;
		ft_separate_in_b(p, (*(p->nb_a) / 2));
		free(tmp);
	}
	if (!(ft_tab_is_sort(p->tab_a, (unsigned int)p->size)))
		ft_op_sa(p, 0, 1);
}

void	ft_sort_little_a(t_params *p)
{
	int	s_a;

	s_a = p->size - *(p->nb_a);
	if (p->tab_a[p->size - 1] > p->tab_a[s_a])
	{
		if (p->tab_a[s_a] > p->tab_a[s_a + 1])
			ft_op_sa(p, 0, 1);
		else if (p->tab_a[s_a + 1] > p->tab_a[p->size - 1])
		{
			ft_op_rotate_a(p, 0, 1);
			ft_op_sa(p, 0, 1);
			ft_op_reverse_rotate_a(p, 0, 1);
		}
	}
	else if (p->tab_a[s_a] > p->tab_a[p->size - 1])
	{
		if (p->tab_a[s_a + 1] > p->tab_a[p->size - 1])
		{
			if (p->tab_a[s_a + 1] < p->tab_a[s_a])
				ft_op_sa(p, 0, 1);
			ft_op_reverse_rotate_a(p, 0, 1);
		}
		else if (p->tab_a[s_a + 1] < p->tab_a[p->size - 1])
			ft_op_rotate_a(p, 0, 1);
	}
}

void	ft_order_a(t_params *p)
{
	int	start_a;

	start_a = p->size - *(p->nb_a);
	if (ft_tab_is_sort(p->tab_a, (unsigned int)(p->size)))
		return ;
	else if (*(p->nb_a) <= 3)
		ft_sort_little_a(p);
	else
	{
		ft_sort_big_a(p);
		if (*(p->nb_a) <= 3)
			ft_sort_little_a(p);
	}
}
