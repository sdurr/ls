/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_option_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 08:43:54 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/12 11:34:49 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_list		*opt_r(t_list *s)
{
	t_list *t;
	char  *tmp;
	int tmp_n;
	t_list *begin;
	char *path_tmp;

	begin = s;
	t = s;
	s = s->next;
	while (t->next != NULL)
		t = t->next;
	while (s->next != NULL)
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
		t = t->prev;
		s = s->next;
	}
		return (begin);
}
