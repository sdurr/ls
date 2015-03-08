/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 17:27:21 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/05 18:12:40 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_path		*ft_create_elem_path(t_path *t, char *s, int n)
{
	t_path *elem;
	t_path *begin;

	begin = t;
	elem = malloc(sizeof(t_path));
	elem->n = n;
	elem->s = s;
	elem->next = NULL;
	if (t == NULL)
	{
		elem->prev = NULL;
		return (elem);
	}
	while (t->next != NULL)
		t = t->next;
	elem->prev = t;
	t->next = elem;
	return (begin);
}
