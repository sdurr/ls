/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 13:30:27 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/14 14:12:12 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

int			print_list(t_list *s)
{
	while (s)
	{
		if (s->n == 2)
		{
			if (ft_strcmp(s->s, ". :") != 0)
			{
				ft_putchar ('\n');
				ft_putendl(s->s);
			}
			s = s->next;
			if (s->n != 2)
			{
				s = s->prev;
				nb_blocks(s);
			}
			else
				s = s->prev;
		}
		else
			ft_putendl(s->s);
		s = s->next;
	}
	return (0);
}
