/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpanikka <kpanikka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:17:05 by kpanikka          #+#    #+#             */
/*   Updated: 2022/09/26 18:59:43 by kpanikka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_error(t_pswap *ps, char *s, int flag)
{
	if (s)
		free(s);
	if (ps->data)
		free(ps->data);
	if (flag == 3)
	{
		free(ps->result);
		ps->result = NULL;
	}
	if (ps->sa)
		ft_dlstclear(&(ps->sa));
	if (ps->sb)
		ft_dlstclear(&ps->sb);
	if (!flag || flag == 3)
	{
		write(2, "Error\n", 6);
	}
	exit(0);
}

void	init_pswap(t_pswap *ps)
{
	ps->i = 0;
	ps->j = 0;
	ps->sa = NULL;
	ps->sb = NULL;
	ps->data = NULL;
	ps->result = NULL;
	ps->count_stack = 1;
	ps->count = 0;
}

int	main(int argc, char **argv)
{
	t_pswap	ps;

	if (argc < 2)
		return (0);
	init_pswap(&ps);
	while (++ps.i < argc)
	{
		ps.data = ft_split(argv[ps.i], &ps.count, &ps);
		ps.count_stack += ps.count;
		while (ps.j < ps.count && is_duplicate(ps.sa, ps.data[ps.j], &ps))
			ft_dlstadd_back(&ps.sa, ft_dlstnew(ps.data[ps.j++]));
		ps.j = 0;
		free(ps.data);
		ps.data = NULL;
	}
	if (is_sorted(ps.sa))
		ft_error(&ps, NULL, 1);
	ft_index_stack(ps.sa, ps.count_stack);
	ft_small_sorts(&ps);
	ps.i = 0;
	while ((ps.count_stack - 1) >> ps.i++)
		ps.sa = ft_sort_elements(ps.sa, ps.sb, ps.count_stack);
	ft_error(&ps, NULL, 1);
	return (0);
}
