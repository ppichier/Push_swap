/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr2d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:15:00 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:21:15 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr2d(char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
}