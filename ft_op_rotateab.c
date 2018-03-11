/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_op_rotateab.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/18 18:22:45 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/27 19:36:44 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_op_rotate_a(t_params *p, int k, int p_s)
{
	int start_a;
	int i;
	int tmp;
	int j;

	start_a = p->size - *(p->nb_a);
	i = start_a;
	j = p->size - 1;
	if (*(p->nb_a) > 1)
	{
		tmp = p->tab_a[i];
		while (i < j)
		{
			p->tab_a[i] = p->tab_a[i + 1];
			i++;
		}
		p->tab_a[j] = tmp;
	}
	if (k == 0 && p_s == 1)
		write(1, "ra\n", 3);
}

void	ft_op_rotate_b(t_params *p, int k, int p_s)
{
	int start_b;
	int i;
	int tmp;
	int j;

	start_b = p->size - *(p->nb_b);
	i = start_b;
	j = p->size - 1;
	if (*(p->nb_b) > 1)
	{
		tmp = p->tab_b[i];
		while (i < j)
		{
			p->tab_b[i] = p->tab_b[i + 1];
			i++;
		}
		p->tab_b[j] = tmp;
	}
	if (k == 0 && p_s == 1)
		write(1, "rb\n", 3);
}

void	ft_op_rotate_rr(t_params *p, int p_s)
{
	ft_op_rotate_a(p, 1, p_s);
	ft_op_rotate_b(p, 1, p_s);
	if (p_s == 1)
		write(1, "rr\n", 3);
}
