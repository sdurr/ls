/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 09:02:40 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/11 12:10:15 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

t_list		*open_list(t_list *s, char c)
{
	t_list *begin;
	t_list *add;
	t_list *add_2;
//	t_list *s_path;

	add = malloc(sizeof(t_list));
	add = NULL;
	add_2 = add;
	begin = s;
	while (s->next != NULL)
	{
		if (s->n == 1)
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
		s = s->next;
	}
	if (s->n == 1)
	{
		add = ft_ls_read(s->path, add, c);
		s->n = 0;
		add->prev = s;
		s->next = add;
		s = begin;
		add = add_2;
	}
	return (begin);
}
