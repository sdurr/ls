/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_option_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 08:43:54 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/13 17:50:48 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static t_list	*end_link(t_list *s, t_list *t)
{
	t_list *begin;

	begin = s;
	while (s->next != NULL)
	{
		if (ft_strcmp(s->s, t->s) > 0)
			s = exchange_link(s, t);
		s = s->next;
	}
	return (begin);
}

t_list			*tri_ascii(t_list *s)
{
	t_list		*t;
	t_list		*begin;

	begin = s;
	t = s;
	t = t->next;
	while (s->next != NULL)
	{
		if (s->n == 2 && (s = s->next))
			t = t->next;
		while (s->n != 2 && s->next != NULL)
		{
			while (t->next != NULL && t->n != 2)
			{
				if (ft_strcmp(s->s, t->s) > 0)
					s = exchange_link(s, t);
				t = t->next;
			}
			t = s;
			t = t->next;
			s = s->next;
		}
	}
	s = end_link(begin, t);
	return (begin);
}
