/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
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

t_list		*ft_create_elem(t_list *t, char *s, int n)
{
	t_list *elem;
	t_list *begin;

	begin = t;
	elem = malloc(sizeof(t_list));
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
