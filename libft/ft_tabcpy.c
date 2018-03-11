/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tabcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 19:26:02 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 20:03:53 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

intmax_t	*ft_tabcpy(intmax_t *tab, unsigned int size)
{
	unsigned int	i;
	intmax_t		*tmp;

	if (!tab)
		return (NULL);
	if (!(tmp = (intmax_t*)malloc(sizeof(*tmp) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		tmp[i] = tab[i];
		i++;
	}
	return (tmp);
}
