/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_op_pab.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/18 15:52:29 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/27 19:35:35 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_op_pa(t_params *p, int p_s)
{
	int start_a;
	int start_b;

	start_a = p->size - *(p->nb_a);
	start_b = p->size - *(p->nb_b);
	if (*(p->nb_b) > 0)
	{
		p->tab_a[start_a - 1] = p->tab_b[start_b];
		p->tab_b[start_b] = '\0';
		*(p->nb_a) = *(p->nb_a) + 1;
		*(p->nb_b) = *(p->nb_b) - 1;
	}
	if (p_s == 1)
		write(1, "pa\n", 3);
}

void	ft_op_pb(t_params *p, int p_s)
{
	int start_a;
	int start_b;

	start_a = p->size - *(p->nb_a);
	start_b = p->size - *(p->nb_b);
	if (*(p->nb_a) > 0)
	{
		p->tab_b[start_b - 1] = p->tab_a[start_a];
		p->tab_a[start_a] = '\0';
		*(p->nb_a) = *(p->nb_a) - 1;
		*(p->nb_b) = *(p->nb_b) + 1;
	}
	if (p_s == 1)
		write(1, "pb\n", 3);
}
