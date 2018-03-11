/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cmptab.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 12:35:52 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 12:39:09 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_cmptab(int *tab1, int *tab2, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		if (tab1[i] != tab2[i])
			return (0);
		i++;
	}
	return (1);
}
