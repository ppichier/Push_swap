/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_int_tab.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/09 17:43:23 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/13 19:26:28 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_sort_int_tab_int(int *tab, unsigned int size, int k)
{
	unsigned int	i;
	unsigned int	j;
	int				tmp;
	int				*tmp_tab;

	tmp_tab = ft_tabcpy_int(tab, size);
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp_tab[i] > tmp_tab[j])
			{
				tmp = tmp_tab[i];
				tmp_tab[i] = tmp_tab[j];
				tmp_tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	tmp = tmp_tab[k];
	free(tmp_tab);
	return (tmp);
}
