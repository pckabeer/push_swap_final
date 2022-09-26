/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpanikka <kpanikka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 09:47:30 by kpanikka          #+#    #+#             */
/*   Updated: 2022/09/26 19:12:12 by kpanikka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_atoi(char *str, t_pswap *ps)
{
	int				i;
	int				sign;
	unsigned long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i++] - '0';
		if (num >= 2147483648 && sign == 1)
			ft_error(ps, str, 3);
		else if (num > 2147483648 && sign == -1)
			ft_error(ps, str, 3);
	}
	if (str[i] || (str[0] == '+' && !str[1]) || (str[0] == '-' && !str[1]))
		ft_error(ps, str, 3);
	free(str);
	str = NULL;
	return (num * sign);
}

int	is_duplicate(t_stack *lst, int num, t_pswap *pa)
{
	while (lst)
	{
		if (lst->data == num)
			ft_error(pa, NULL, 0);
		lst = lst->next;
	}
	return (1);
}

void	lst_print(t_stack *lst)
{
	t_stack	*temp;

	temp = lst;
	while (temp)
	{
		temp = temp->next;
	}
}
