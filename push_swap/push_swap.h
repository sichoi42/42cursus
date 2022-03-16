/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:46:41 by sichoi            #+#    #+#             */
/*   Updated: 2021/08/21 16:34:17 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
typedef struct s_data
{
	int	value;
	int	rank;
}	t_data;

typedef struct s_stack	*t_pointer;
typedef struct s_stack
{
	t_data		data;
	int			count;
	t_pointer	llink;
	t_pointer	rlink;
	t_pointer	top;
}	t_stack;

/*sorting.c*/
int				sorting(t_pointer head_a);
void			sorting_three(t_pointer head_a, t_pointer head_b);
void			sorting_four(t_pointer head_a, t_pointer head_b);
void			sorting_five(t_pointer head_a, t_pointer head_b);
void			radix_sort(t_pointer head_a, t_pointer head_b);
/*ft_split.c*/
int				count_row(const char *s, char c);
char			**free_if_fail(char **split, int size);
char			**put_split(char const *s, char c, int row, char **split);
char			**ft_split(char const *s, char c);
/*ft_util1.c*/
int				ft_strlen(const char *s);
int				ft_strlcpy(char *dst, const char *src, int dstsize);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
long long		ft_atoi(const char *s);
/*ft_util2.c*/
int				is_digit(const char *s);
int				is_sorted(t_pointer head);
void			get_rank(t_pointer head);
void			init_rank(t_pointer head_a, t_pointer head_b);
/*stacks.c*/
int				init_stack(int value, t_pointer head);
int				push_stack(t_data data, t_pointer head);
t_data			pop(t_pointer head);
t_pointer		free_stack(t_pointer head);
/*swap.c*/
void			swap(t_pointer head);
void			sa(t_pointer head_a);
void			sb(t_pointer head_b);
void			ss(t_pointer head_a, t_pointer head_b);
/*push.c*/
int				pa(t_pointer head_b, t_pointer head_a);
int				pb(t_pointer head_a, t_pointer head_b);
/*rotate.c*/
void			ra(t_pointer head_a);
void			rb(t_pointer head_b);
void			rr(t_pointer head_a, t_pointer head_b);
/*reverse_rotate.c*/
void			rra(t_pointer head_a);
void			rrb(t_pointer head_b);
void			rrr(t_pointer head_a, t_pointer head_b);
#endif
