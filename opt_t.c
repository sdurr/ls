/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_option_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 08:43:54 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/16 11:38:52 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static	t_list		*end_link(t_list *s, t_list *t)
{
	struct stat		first;
	struct stat		second;
	t_list			*begin;

	begin = s;
	while (s->n != 2 && s->next != NULL)
	{
		lstat(t->path, &first);
		lstat(s->path, &second);
		if (first.st_mtime > second.st_mtime)
			s = exchange_link(s, t);
		else
			s = s->next;
	}
	return (begin);
}

t_time				stat_time(char *t_path, char *s_path)
{
	t_time			e;
	struct stat		first;
	struct stat		second;

	lstat(t_path, &first);
	lstat(s_path, &second);
	e.first = first.st_mtime;
	e.second = second.st_mtime;
	return (e);
}

t_list				*opt_t(t_list *s)
{
	t_time			e;
	t_list			*t;
	t_list			*begin;

	begin = s;
	t = s;
	while (s->next != NULL)
	{
		if (s->n == 2 && (s = s->next))
			t = t->next;
		while ((t = t->next) && s->n != 2 && s->next != NULL)
		{
			while (t->n != 2 && t->next != NULL)
			{
				e = stat_time(t->path, s->path);
				if (e.first > e.second)
					s = exchange_link(s, t);
				t = t->next;
			}
			t = s;
			s = s->next;
		}
	}
	return (end_link(begin, t));
}
