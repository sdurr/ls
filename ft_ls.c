/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 17:41:36 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/16 15:09:28 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdio.h>

void		print_files(int flags, char *av)
{
	t_list *s;

	s = malloc(sizeof(t_list));
	s->s = ft_strdup(av);
	s->path = ft_strjoin("./", av);
	s->s += 2;
	if (flags & OPT_L)
		s = opt_l(s);
	ft_putendl(s->s);
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
			if (av[nb][0] != '/')
				av[nb] = ft_strjoin("./", av[nb]);
			if (test_perm(av[nb]) == 1)
			{
				if (test_open(av[nb]) == 0)
				{
					if (test_files(av[nb]) != NULL)
						print_files(flags, av[nb]);
					else
						no_files(av[nb]);
				}
				else
					s = ft_ls_read(av[nb], s, c);
				nb++;
			}
		}
	}
	if (s == NULL)
		exit (0);
	return (s);
}
