/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tabcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 19:26:02 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 22:53:47 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		*ft_tabcpy_int(int *tab, unsigned int size)
{
	unsigned int	i;
	int				*tmp;

	if (!tab)
		return (NULL);
	if (!(tmp = (int*)malloc(sizeof(*tmp) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		tmp[i] = tab[i];
		i++;
	}
	return (tmp);
}
