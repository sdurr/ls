/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:33:59 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/11 14:13:04 by sdurr            ###   ########.fr       */
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
		while (s->next != NULL)
			s = s->next;
		while (s->prev != NULL)
		{
			ft_putendl(s->s);
			s = s->prev;
		}
		return (0);
	}
	while (s)
	{
		if (ft_strchr(s->s, ':') != NULL && ft_strchr(s->s, '/') != NULL)
			ft_putchar ('\n');
		ft_putstr(s->s);
		ft_putchar ('\n');
		s = s->next;
		}
	return (0);
}
