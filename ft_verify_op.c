/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_verify_op.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 16:46:14 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/05 19:52:09 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_pushswap.h"

static	int		ft_op_cmp(char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		return (1);
	if (ft_strcmp(str, "sb") == 0)
		return (1);
	if (ft_strcmp(str, "ss") == 0)
		return (1);
	if (ft_strcmp(str, "pa") == 0)
		return (1);
	if (ft_strcmp(str, "pb") == 0)
		return (1);
	if (ft_strcmp(str, "ra") == 0)
		return (1);
	if (ft_strcmp(str, "rb") == 0)
		return (1);
	if (ft_strcmp(str, "rr") == 0)
		return (1);
	if (ft_strcmp(str, "rra") == 0)
		return (1);
	if (ft_strcmp(str, "rrb") == 0)
		return (1);
	if (ft_strcmp(str, "rrr") == 0)
		return (1);
	return (0);
}

static	void	ft_apply_op(t_params *p, char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		ft_op_sa(p, 0, 0);
	else if (ft_strcmp(str, "sb") == 0)
		ft_op_sb(p, 0, 0);
	else if (ft_strcmp(str, "ss") == 0)
		ft_op_ss(p, 0);
	else if (ft_strcmp(str, "pa") == 0)
		ft_op_pa(p, 0);
	else if (ft_strcmp(str, "pb") == 0)
		ft_op_pb(p, 0);
	else if (ft_strcmp(str, "ra") == 0)
		ft_op_rotate_a(p, 0, 0);
	else if (ft_strcmp(str, "rb") == 0)
		ft_op_rotate_b(p, 0, 0);
	else if (ft_strcmp(str, "rr") == 0)
		ft_op_rotate_rr(p, 0);
	else if (ft_strcmp(str, "rra") == 0)
		ft_op_reverse_rotate_a(p, 0, 0);
	else if (ft_strcmp(str, "rrb") == 0)
		ft_op_reverse_rotate_b(p, 0, 0);
	else if (ft_strcmp(str, "rrr") == 0)
		ft_op_reverse_rotate_rr(p, 0);
}

void			ft_verify_op(t_params *p)
{
	char	*str;
	int		j;

	j = 0;
	while (get_next_line(0, &str))
	{
		if (ft_op_cmp(str) == 0)
		{
			write(2, "Error\n", 6);
			free(str);
			return ;
		}
		else
		{
			ft_apply_op(p, str);
			free(str);
		}
		j = 1;
	}
	if (ft_tab_is_sort(p->tab_a, (unsigned int)p->size) == 1 && *(p->nb_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
