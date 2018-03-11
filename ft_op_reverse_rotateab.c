/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_op_reverse_rotateab.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/18 20:04:34 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/27 19:37:15 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_op_reverse_rotate_a(t_params *p, int k, int p_s)
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
		tmp = p->tab_a[j];
		while (i < j)
		{
			p->tab_a[j] = p->tab_a[j - 1];
			j--;
		}
		p->tab_a[i] = tmp;
	}
	if (k == 0 && p_s == 1)
		write(1, "rra\n", 4);
}

void	ft_op_reverse_rotate_b(t_params *p, int k, int p_s)
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
		tmp = p->tab_b[j];
		while (i < j)
		{
			p->tab_b[j] = p->tab_b[j - 1];
			j--;
		}
		p->tab_b[i] = tmp;
	}
	if (k == 0 && p_s == 1)
		write(1, "rrb\n", 4);
}

void	ft_op_reverse_rotate_rr(t_params *p, int p_s)
{
	ft_op_reverse_rotate_a(p, 1, p_s);
	ft_op_reverse_rotate_b(p, 1, p_s);
	if (p_s == 1)
		write(1, "rrr\n", 4);
}
