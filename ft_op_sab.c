/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_op_push.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 19:44:14 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/27 19:35:01 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_op_sa(t_params *p, int k, int p_s)
{
	int tmp;
	int i;
	int start;

	i = 0;
	start = p->size - *(p->nb_a);
	if ((*p->nb_a) > 1)
	{
		tmp = p->tab_a[start];
		p->tab_a[start] = p->tab_a[start + 1];
		p->tab_a[start + 1] = tmp;
	}
	if (k == 0 && p_s == 1)
		write(1, "sa\n", 3);
}

void	ft_op_sb(t_params *p, int k, int p_s)
{
	int tmp;
	int i;
	int start;

	i = 0;
	start = p->size - *(p->nb_b);
	if (*(p->nb_b) > 1)
	{
		tmp = p->tab_b[start];
		p->tab_b[start] = p->tab_b[start + 1];
		p->tab_b[start + 1] = tmp;
	}
	if (k == 0 && p_s == 1)
		write(1, "sb\n", 3);
}

void	ft_op_ss(t_params *p, int p_s)
{
	ft_op_sa(p, 1, p_s);
	ft_op_sb(p, 1, p_s);
	if (p_s == 1)
		write(1, "ss\n", 3);
}
