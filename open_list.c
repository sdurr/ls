/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 09:02:40 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/16 09:13:18 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static t_list *open_list2(t_list *s, t_list *add, t_list *begin, int c)
{
	t_list *add_f;
	t_list *add_2;

	add_f = malloc(sizeof(t_list));
	add_f = NULL;
	add_2 = add;
	if (ft_strcmp(s->s, ".") != 0 && ft_strcmp(s->s, "..") != 0)
	{
		add = ft_ls_read(s->path, add, c);
		s->n = 0;
		while (s->next != NULL)
			s = s->next;
		add->prev = s;
		s->next = add;
		s = begin;
		add = add_2;
	}
	else
		s->n = 0;
	return (s);
}

t_list		*open_list(t_list *s, char c)
{
	t_list *begin;
	t_list *add;

	add = malloc(sizeof(t_list));
	add = NULL;
	begin = s;
	while (s->next != NULL)
	{
		if (s->n == 1)
		{
			s = open_list2(s, add, begin, c);
		}
		s = s->next;
	}
	if (s->n == 1)
	{
		add = ft_ls_read(s->path, add, c);
		s->n = 0;
		add->prev = s;
		s->next = add;
	}
	return (begin);
}
