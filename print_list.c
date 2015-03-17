/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 13:30:27 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/17 16:05:06 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static int	test(t_list *s)
{
	if (ft_strcmp(s->s, ":") != 0 && ft_strcmp(s->s, ". :")
		&& ft_strcmp(s->s, "/ :") != 0)
		return (1);
	return (0);
}

int			print_list(t_list *s, int flags)
{
	while (s)
	{
		if (s->n == 2)
		{
			if (!(flags & OPT_R_R) && (s->s[0] != '/'))
				s->s += 2;
			if (test(s) == 1 && s->next != NULL)
			{
				ft_putchar ('\n');
				ft_putendl(s->s);
			}
			if (s->next == NULL)
				return (0);
			s = s->next;
			if (s->n != 2 && (s = s->prev))
				nb_blocks(s);
			else if (s)
				s = s->prev;
		}
		else
			ft_putendl(s->s);
		s = s->next;
	}
	return (0);
}
