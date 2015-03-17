/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 17:41:36 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/17 15:30:27 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdio.h>

void		print_files(int flags, char *av)
{
	t_list *s;

	if (test_files(av) != NULL)
	{
		s = malloc(sizeof(t_list));
		s->s = ft_strdup(av);
		if (s->s[0] != '/')
		{
			s->path = ft_strjoin("./", av);
			s->s += 2;
		}
		else
			s->path = ft_strdup(av);
		if (flags & OPT_L)
			s = opt_l(s);
		ft_putendl(s->s);
	}
	else
		no_files(av);
}

static char *test_av(char **av, int nb)
{
	if (ft_strcmp(av[nb], "") == 0)
		return (".");
	return (av[nb]);
}

t_list		*ft_ls(char **av, int nb, char c, int flags)
{
	t_list *s;

	s = malloc(sizeof(t_list));
	s = NULL;
	if (!(av[++nb]))
		s = ft_ls_read(".", s, c);
	else
	{
		while (av[nb] != NULL)
		{
			if (av[nb][0] != '/' && (av[nb] = test_av(av, nb)))
				av[nb] = ft_strjoin("./", av[nb]);
			if (test_perm(av[nb]) == 1)
			{
				if (test_open(av[nb]) == 0)
					print_files(flags, av[nb]);
				else
					s = ft_ls_read(av[nb], s, c);
			}
			nb++;
		}
	}
	if (s == NULL)
		exit (0);
	return (s);
}
