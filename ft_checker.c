/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_checker.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 15:31:46 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/27 19:38:29 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_pushswap.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_split_arg(argv[1], 0) == 0)
			write(2, "Error\n", 6);
	}
	else if (argc > 2)
	{
		if (!ft_check_argv(argv, 0, 0))
			write(2, "Error\n", 6);
	}
	return (0);
}
