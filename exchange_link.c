/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exchange_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 17:47:39 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/13 17:50:17 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

t_list	*exchange_link(t_list *s, t_list *t)
{
	t_ascii a;

	a.tmp = ft_strdup(t->s);
	a.tmp_n = t->n;
	a.path = ft_strdup(t->path);
	t = transfer(t, s->s, s->path, s->n);
	s = transfer(s, a.tmp, a.path, a.tmp_n);
	return (s);
}
