/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:33:59 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/12 13:45:03 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>
#include "libft.h"

int		main(int ac, char **av)
{
	int		flags;
	t_list *s;
	int nb;

	flags = 0;
	s = malloc(sizeof(t_list));
	s = NULL;
	if ((flags = test_option(av, 0, 0, &nb)) == -1)
		return (0);
	if (ac > 0)
		s = ret_ls(s, av, flags, nb);
	if (flags & OPT_R)
	{
		while (s)
		{
			while (s->next != NULL)
						s = s->next;
			while (s->n != 2 && s->prev != NULL)
				s = s->prev;
			if (s->n == 2 && s->next != NULL)
			{
				if (ft_strcmp(s->s, ". :") != 0 &&  ac - nb != 2)
				{
					ft_putchar ('\n');
					ft_putstr(s->s);
					ft_putchar ('\n');
				}
				if (s->next != NULL)
				{
					nb_blocks(s);
					s = s->next;
				}
			}
			while (s->n != 2 && s->next != NULL)
				s = s->next;
			while (s->n != 2 && s->prev != NULL)
			{
				ft_putstr(s->s);
				ft_putchar ('\n');
				s = s->prev;
			}
			if (s->prev != NULL)
				s = s->prev;
			if (s->next == NULL)
				return (0);
			s->next = NULL;
		}
	}
		else
		{
			while (s)
			{
				if ((ft_strchr(s->s, ':') != NULL && ft_strchr(s->s, '/') != NULL) || (ft_strcmp(s->s, ". :") == 0))
				{
					if (ft_strcmp(s->s, ". :") != 0)
					{
						ft_putchar ('\n');
						ft_putstr(s->s);
						ft_putchar ('\n');
					}
					nb_blocks(s);
				}
				else
				{
					ft_putstr(s->s);
					ft_putchar ('\n');
				}
				s = s->next;
			}
		}
	return (0);
}
