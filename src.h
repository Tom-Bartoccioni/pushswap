/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:57:26 by tbartocc          #+#    #+#             */
/*   Updated: 2024/09/02 14:04:53 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H

# include "./Printf/printf.h"

typedef struct s_lst
{
	int				number;

	struct s_lst	*prev;
	struct s_lst	*next;
}	t_lst;

typedef struct s_rotate
{
	int	cost_a;
	int	cost_b;
	int	uncommon_cost;
	int	ra_or_rra;
	int	rb_or_rrb;
}	t_rotate;

void	error(void);
int		is_duplicate(t_lst *lst, int number);
int		is_sorted(t_lst *lst_a);
void	ft_lst_add_back(t_lst **lst, t_lst *new);
t_lst	*ft_lst_last(t_lst *lst);
t_lst	*ft_lst_new(int number);
int		ft_lst_position(t_lst *lst, t_lst *element);
int		ft_lst_size(t_lst *lst);
t_lst	*find_max(t_lst *lst);
t_lst	*find_min(t_lst *lst);
void	pa(t_lst **a, t_lst **b);
void	pb(t_lst **a, t_lst **b);
void	sa(t_lst **lst);
void	sb(t_lst **lst);
void	ss(t_lst **lst_a, t_lst **lst_b);
void	ra(t_lst **lst);
void	rb(t_lst **lst);
void	rr(t_lst **lst_a, t_lst **lst_b);
void	rra(t_lst **lst);
void	rrb(t_lst **lst);
void	rrr(t_lst **lst_a, t_lst **lst_b);
void	op(char *op, t_lst **lst_a, t_lst **lst_b);
void	push_smallest(t_lst **lst_a, t_lst **lst_b);
void	sort(t_lst **lst_a, t_lst **lst_b);
void	sort_three(t_lst **a, t_lst **lst_b);
void	sort_four(t_lst **lst_a, t_lst **lst_b);
void	sort_five(t_lst **lst_a, t_lst **lst_b);
void	rotation_a(t_lst **lst_a, t_lst **lst_b, int cost_a);
void	rotation_b(t_lst **lst_a, t_lst **lst_b, int cost_b);
void	rotate_to_top(t_lst **lst_a, t_lst **lst_b, char a_b);
int		find_position_in_a(t_lst *element, t_lst *lst_a);
int		find_position_in_b(t_lst *element, t_lst *lst_b);
void	ft_print_list(t_lst *lst, t_lst *lst_b);
void	push_back(t_lst **lst_a, t_lst **lst_b);
void	opti_rotate(t_lst *cheapest, t_lst **lst_a, t_lst **lst_b);
void	ft_free_lst(t_lst *lst);
void	ft_free_tab(char **tab);
void	ft_free_tab_lst_exit(char **tab, t_lst *lst);
t_lst	*parsing(char **tab, t_lst *lst_a);
char	*get_next_line(int fd);

#endif
