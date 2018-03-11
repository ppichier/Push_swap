/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_rev_tab.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 11:31:06 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/22 11:33:37 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_sort_rev_tab(int *tab, unsigned int size, int nb_a)
{
	unsigned int i;

	i = 0;
	while (i < size - (unsigned int)nb_a)
		i++;
	while (i < size - 1)
	{
		if (tab[i] < tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
