/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpanikka <kpanikka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:14:56 by kpanikka          #+#    #+#             */
/*   Updated: 2022/09/26 15:30:47 by kpanikka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_elements
{
	int					data;
	int					index;
	struct s_elements	*next;
	struct s_elements	*prev;
}t_stack;

typedef struct pushswap
{
	int		i;
	int		*data;
	int		j;
	t_stack	*sa;
	t_stack	*sb;
	int		count;
	int		count_stack;
	int		*result;
}	t_pswap;

int		*ft_split(char *s, int *c, t_pswap *ps);
int		ft_atoi(char *str, t_pswap *ps);
int		is_duplicate(t_stack *lst, int num, t_pswap *pa);
void	ft_error(t_pswap *ps, char *s, int flag);

void	ft_rotate_stack(t_stack **sa);
void	ft_rrotate_stack(t_stack **sa);
void	sa(t_stack **a);

void	ft_pusha(t_stack **a, t_stack **b);
void	ft_pushb(t_stack **a, t_stack **b);
void	stack_index(t_stack *a);
void	stack_index_bit_shit(t_stack *b);
void	lst_print(t_stack *lst);
void	ft_index_stack(t_stack *a, int count);

//double lst
t_stack	*ft_dlstnew(int data);

void	ft_dlstadd_back(t_stack **lst, t_stack *new);
void	ft_dlstadd_front(t_stack **lst, t_stack *new);
int		ft_dlstsize(t_stack *lst);
void	ft_dlstclear(t_stack **lst);
t_stack	*ft_dlstlast(t_stack *lst);

void	ft_index_shift(t_stack *s);

t_stack	*ft_sort_elements(t_stack *a, t_stack *b, int count);
void	ft_small_sorts(t_pswap *ps);
void	sort_three(t_pswap *ps);
void	sort_three_c(t_pswap *ps);
int		is_sorted(t_stack *s);

#endif
