/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_option_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 08:43:54 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/09 11:42:55 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_list		*opt_t(t_list *s)
{
	struct stat first;
	struct stat second;
	t_list *t;
	char  *tmp;
	int tmp_n;
	t_list *begin;

	begin = s;
	t = s;
	t = t->next;
	t = t->next;
	s = s->next;
	while (s)
	{
		while (t->next != NULL)
		{
			lstat(t->s, &first);
			lstat(s->s, &second);
			if (first.st_mtime < second.st_mtime)
			{
				tmp = t->s;
				tmp_n = t->n;
				t->s = s->s;
				t->n = s->n;
				s->s = tmp;
				s->n = tmp_n;
			}
			else
				t = t->next;
		}
		t = s;
		t = t->next;
		s = s->next;
	}
	return (begin);
}
