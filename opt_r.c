/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_option_R.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 14:25:46 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/11 16:20:39 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include "libft.h"

t_list 	*opt_r(t_list *s)
{
	t_list *next;
	t_list *begin;
	char *s1;
	char *path;
	int n;

	begin = s;
	next = s;
	while (next->next != NULL)
		next = next->next;
	while (s->next != NULL)
	{
		s1 = ft_strdup(next->s);
		path = ft_strdup(next->path);
		n = next->n;
		next->s = ft_strdup(s->s);
		next->path = ft_strdup(s->path);
		next->n = s->n;
		s->s = ft_strdup(s1);
		s->path = ft_strdup(path);
		s->n = n;
		next = next->prev;
		s = s->next;
	}
	return (begin);
}
