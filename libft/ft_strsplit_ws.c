/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit_ws.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 15:40:39 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 15:51:00 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbwords(char const *s)
{
	int i;
	int nb;

	nb = 0;
	i = 0;
	if (s == NULL)
		return (0);
	if (!(WSP(s[0])) && s[0] != '\0')
		nb++;
	while (s[i] != '\0')
	{
		if (!(WSP(s[i])) && WSP(s[i - 1]))
			nb++;
		i++;
	}
	return (nb);
}

static char	*ft_nbletters(char const *s, int i)
{
	char	*tab;

	if (s == NULL)
		return (0);
	while (!(WSP(s[i])) && s[i] != '\0')
		i++;
	if (!(tab = (char*)malloc(sizeof(*tab) * (i + 1))))
		return (NULL);
	return (tab);
}

char		**ft_strsplit_ws(char const *s)
{
	char	**dest;
	int		i;
	int		j;
	int		ptr;

	i = 0;
	ptr = 0;
	if (s == NULL)
		return (NULL);
	if (!(dest = (char**)malloc(sizeof(*dest) * (ft_nbwords(s) + 1))))
		return (NULL);
	while (i < ft_nbwords(s))
	{
		j = 0;
		while (WSP(s[ptr]) && s[ptr] != '\0')
			ptr++;
		if ((dest[i] = ft_nbletters(s, ptr)) == NULL)
			return (NULL);
		while (!(WSP(s[ptr])) && s[ptr] != '\0')
			dest[i][j++] = s[ptr++];
		dest[i++][j] = '\0';
	}
	dest[i] = 0;
	return (dest);
}
