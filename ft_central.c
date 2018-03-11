/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_central.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/18 15:40:30 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 09:46:47 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_pushswap.h"

static	void	ft_generate_pile_b(t_params *params)
{
	int i;

	i = 0;
	params->tab_b = (int*)malloc(sizeof(*params->tab_b) * (params->size));
	while (i < params->size)
	{
		params->tab_b[i] = '\0';
		i++;
	}
}

void			ft_central(int *tab_a, int *size_a, int ps_active)
{
	t_params	*params;
	int			a;

	a = 0;
	params = (t_params*)malloc(sizeof(*params));
	params->tab_a = tab_a;
	params->size = *(size_a);
	params->nb_a = size_a;
	params->nb_b = &a;
	ft_generate_pile_b(params);
	if (ps_active == 1)
	{
		ft_algo_sort(params);
		free(params->tab_a);
		free(params->tab_b);
		free(params->tab_sort);
	}
	else if (ps_active == 0)
	{
		ft_verify_op(params);
		free(params->tab_a);
		free(params->tab_b);
	}
	free(params);
}
