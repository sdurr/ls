/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 09:00:52 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/11 11:12:27 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

int			test_dir(t_list *s, char c)
{
	t_list *begin;

	begin = s;
	if (c == '.')
		ft_putstr("blabla");
	while (s->next != NULL)
	{
			ft_putstr(s->s);
			ft_putstr(" open = ");
			ft_putnbr(s->n);
			ft_putchar ('\n');
	if (s->n == 1)
		{
					s = begin;
			return (1);
		}
		s = s->next;
	}
	s = begin;
	return (0);
}
