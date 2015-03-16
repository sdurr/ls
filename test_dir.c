/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 09:00:52 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/16 10:59:41 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

int			test_dir(t_list *s)
{
	t_list *begin;

	begin = s;
	if (s)
		while (s->next != NULL)
		{
			if (s->n == 1)
		{
			s = begin;
			return (1);
		}
		s = s->next;
	}
	s = begin;
	return (0);
}
