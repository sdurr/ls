/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_option_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 08:43:54 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/12 14:01:44 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_list		*opt_t(t_list *s)
{
	struct	stat	first;
	struct	stat	second;
	t_list	*t;
	char	*tmp;
	int		tmp_n;
	t_list	*begin;
	char	*path_tmp;

	begin = s;
	t = s;
	t = t->next;
	t = t->next;
	while (s->next != NULL)
	{
		if (s->n == 2)
		{
			s = s->next;
			t = t->next;
		}
		while (s->n != 2 && s->next != NULL)
		{
			while (t->n != 2 && t->next != NULL)
			{
				lstat(t->path, &first);
				lstat(s->path, &second);
				if (first.st_mtime > second.st_mtime)
				{
					tmp = ft_strdup(t->s);
					tmp_n = t->n;
					path_tmp = ft_strdup(t->path);
					t->s = ft_strdup(s->s);
					t->n = s->n;
					t->path = ft_strdup(s->path);
					s->s = ft_strdup(tmp);
					s->n = tmp_n;
					s->path = ft_strdup(path_tmp);
				}
				else
					t = t->next;
			}
			t = s;
			t = t->next;
			s = s->next;
		}
	}
	while (s->prev  != NULL)
	{
		ft_putendl(s->s);
		lstat(t->path, &first);
		lstat(s->path, &second);
		if (first.st_mtime > second.st_mtime)
		{
			tmp = ft_strdup(t->s);
			tmp_n = t->n;
			path_tmp = ft_strdup(t->path);
			t->s = ft_strdup(s->s);
			t->n = s->n;
			t->path = ft_strdup(s->path);
			s->s = ft_strdup(tmp);
			s->n = tmp_n;
			s->path = ft_strdup(path_tmp);
		}
		else
			s = s->prev;
	}
	return (begin);
}
