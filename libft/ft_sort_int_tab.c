/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_int_tab.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/09 17:43:23 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 20:14:32 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_int_tab(intmax_t *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	uintmax_t		tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
