/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pushswap.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 16:33:35 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 15:59:09 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H
# define WS(x) x == ' ' || x == '\n' || x == '\t'
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_params
{
	int				*tab_a;
	int				*tab_b;
	int				size;
	int				*nb_a;
	int				*nb_b;
	int				*tab_sort;
	int				med;
}				t_params;

int				ft_check_argv(char **argv, int p, int ps_active);
int				ft_split_arg(char *argv, int ps_active);
void			ft_central(int *tab_a, int *size_a, int ps_active);
void			ft_algo_sort(t_params *p);
void			ft_op_pa(t_params *p, int p_s);
void			ft_op_pb(t_params *p, int p_s);
void			ft_op_reverse_rotate_a(t_params *p, int k, int p_s);
void			ft_op_reverse_rotate_b(t_params *p, int k, int p_s);
void			ft_op_reverse_rotate_rr(t_params *p, int p_s);
void			ft_op_rotate_a(t_params *p, int k, int p_s);
void			ft_op_rotate_b(t_params *p, int k, int p_s);
void			ft_op_rotate_rr(t_params *p, int p_s);
void			ft_op_sa(t_params *p, int k, int p_s);
void			ft_op_sb(t_params *p, int k, int p_s);
void			ft_op_ss(t_params *p, int p_s);
void			ft_calcul_median(t_params *p);
void			ft_rev_tab_rotate(t_params *p);
int				ft_next_minus_median(t_params *p, int vc, int *tab, int k);
void			ft_rotate_optimal(t_params *p, int value_cmp);
int				ft_indice_insert(t_params *p);
void			ft_separate_in_b(t_params *p, int j);
void			ft_sort_little_a(t_params *p);
void			ft_sort_big_a(t_params *p);
void			ft_order_a(t_params *p);
void			ft_verify_op(t_params *p);
void			ft_export_pile_a(t_params *p);
void			ft_recut(t_params *p, int start);
void			ft_recut_second(t_params *p, int count);
int				ft_portion_is_sort(t_params *p, int count);
void			ft_new_median(t_params *p);
int				ft_median_cut(t_params *p, int count);

#endif
