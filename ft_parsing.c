/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parsing.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 20:49:50 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 16:16:25 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_pushswap.h"

static int		ft_doublon_sizemax_tab(intmax_t *tab, unsigned int size)
{
	intmax_t		*tmp;
	unsigned int	i;

	tmp = ft_tabcpy(tab, size);
	ft_sort_int_tab(tmp, size);
	i = 0;
	if (size == 1 && (tab[0] < -2147483648 || tab[0] > 2147483647))
	{
		free(tmp);
		return (0);
	}
	while (i < size && size > 1)
	{
		if (tmp[i] == tmp[i + 1] || tmp[i] < -2147483648 || tmp[i] > 2147483647)
		{
			free(tmp);
			return (0);
		}
		i++;
	}
	free(tmp);
	return (1);
}

static int		ft_size_argv(char **argv, int p)
{
	int	i;
	int	j;

	i = (p == 0) ? 1 : 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j]) || ((argv[i][j] == '+'
			|| argv[i][j] == '-') && j == 0 && ft_isdigit(argv[i][j + 1]))))
				return (-1);
			j++;
		}
		i++;
	}
	if (p == 0)
		return (i - 1);
	else
		return (i);
}

static int		*ft_cast_tab(intmax_t *tab, unsigned int size)
{
	int				*tmp;
	unsigned int	i;

	i = 0;
	tmp = (int*)malloc(sizeof(*tmp) * size);
	while (i < size)
	{
		tmp[i] = (int)tab[i];
		i++;
	}
	free(tab);
	return (tmp);
}

static void		ft_feel_tab_with_int(char **argv, intmax_t *tab, int p)
{
	int i;
	int j;

	i = (p == 0) ? 1 : 0;
	j = 0;
	while (argv[i])
	{
		tab[j] = ft_atoi_intmax(argv[i]);
		i++;
		j++;
	}
}

int				ft_check_argv(char **argv, int p, int ps_active)
{
	intmax_t	*tab;
	int			len;
	int			*tab2;

	len = ft_size_argv(argv, p);
	tab = (intmax_t*)malloc(sizeof(*tab) * len);
	if (len == -1)
	{
		free(tab);
		return (0);
	}
	ft_feel_tab_with_int(argv, tab, p);
	if (!(ft_doublon_sizemax_tab(tab, (unsigned int)len)))
	{
		free(tab);
		return (0);
	}
	tab2 = ft_cast_tab(tab, (unsigned int)len);
	ft_central(tab2, &len, ps_active);
	return (1);
}
