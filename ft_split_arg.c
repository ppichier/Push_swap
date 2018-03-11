/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split_arg.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 17:20:48 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/27 19:28:58 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_pushswap.h"

static	void	ft_free_my_argv(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int				ft_split_arg(char *argv, int ps_active)
{
	char	**tab;
	int		j;
	int		i;

	j = 0;
	i = 0;
	if (argv == NULL)
		return (0);
	while (argv[i])
	{
		if (!(WS(argv[i])))
			j = 1;
		i++;
	}
	if (j == 0)
		return (1);
	tab = ft_strsplit_ws(argv);
	if (ft_check_argv(tab, 1, ps_active) == 0)
	{
		ft_free_my_argv(tab);
		return (0);
	}
	ft_free_my_argv(tab);
	return (1);
}
