/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 14:01:05 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 19:55:14 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

intmax_t		ft_atoi_intmax(const char *str)
{
	int			i;
	int			j;
	intmax_t	k;

	i = 0;
	j = 0;
	k = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		j = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = k * 10;
		k = k + str[i] - '0';
		i++;
	}
	if (j)
		k = -k;
	return (k);
}
