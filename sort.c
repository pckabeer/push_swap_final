/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpanikka <kpanikka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:09:11 by kpanikka          #+#    #+#             */
/*   Updated: 2022/09/26 18:31:17 by kpanikka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_three_c(t_pswap *ps)
{
	if (ps->sa->data < ps->sa->next->data)
	{
		if (ps->sa-> data < ps->sa->next->next->data
			&& ps->sa->next->data > ps->sa->next->next->data)
		{
			sa(&(ps->sa));
			ft_rotate_stack(&ps->sa);
		}
		if (ps->sa->data > ps->sa->next->next->data
			&& ps->sa->next->data > ps->sa->next->next->data)
			ft_rrotate_stack(&ps->sa);
	}
}

void	sort_three(t_pswap *ps)
{
	if (ps->sa->data > ps->sa->next->data)
	{
		if (ps->sa->data < ps->sa->next->next->data
			&& ps->sa->next->data < ps->sa->next->next->data)
			sa(&(ps->sa));
		if (ps->sa->data > ps->sa->next->next->data
			&& ps->sa->next->data > ps->sa->next->next->data)
		{
			sa(&(ps->sa));
			ft_rrotate_stack(&ps->sa);
		}
		if (ps->sa->data > ps->sa->next->next->data
			&& ps->sa->next->data < ps->sa->next->next->data)
			ft_rotate_stack(&ps->sa);
	}
	sort_three_c(ps);
}

void	ft_small_sorts(t_pswap *ps)
{
	if (ps->count_stack == 4)
	{
		sort_three(ps);
	}
	else if (ps->count_stack == 6)
	{
		while (ps->sa)
		{
			if ((ps->sa->index == 1) || (ps->sa->index == 2))
				ft_pushb(&(ps->sa), &(ps->sb));
			if ((ps->sa->index == 1) || (ps->sa->index == 2))
				ft_pushb(&(ps->sa), &(ps->sb));
			if (ps->sb && ps->sb->next)
				break ;
			ft_rotate_stack(&ps->sa);
		}
		sort_three(ps);
		ft_pusha(&(ps->sb), &(ps->sa));
		ft_pusha(&(ps->sb), &(ps->sa));
		if (ps->sa->index > ps->sa->next->index)
			sa(&ps->sa);
	}
	else
		return ;
	ft_error(ps, NULL, 1);
}

int	is_sorted(t_stack *s)
{
	while (s->next)
	{
		if (s->data > s->next->data)
		{
			return (0);
		}
		s = s->next;
	}
	return (1);
}
