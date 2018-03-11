/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_rec_tools.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 16:02:27 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 16:15:58 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_pushswap.h"

int		ft_portion_is_sort(t_params *p, int count)
{
	int	s_a;
	int	i;

	i = 0;
	s_a = p->size - *(p->nb_a);
	while (i < count - 1)
	{
		if (p->tab_a[s_a] > p->tab_a[s_a + 1])
			return (0);
		i++;
		s_a++;
	}
	return (1);
}

void	ft_new_median(t_params *p)
{
	int		nb;
	int		i;
	int		*tmp;
	int		s_a;

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
	free(tmp);
}

int		ft_median_cut(t_params *p, int count)
{
	int	i[2];
	int	s_a;
	int	cpt;
	int	k;

	i[0] = 0;
	s_a = p->size - *(p->nb_a);
	while (i[0] < count)
	{
		i[1] = p->size - *(p->nb_a);
		cpt = 0;
		k = 0;
		while (k < count)
		{
			if (p->tab_a[s_a] > p->tab_a[i[1]])
				cpt++;
			i[1]++;
			k++;
		}
		if (count / 2 == cpt)
			return (p->tab_a[s_a]);
		i[0]++;
		s_a++;
	}
	return (p->tab_a[count]);
}
