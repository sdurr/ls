/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 17:41:36 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/14 15:54:08 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdio.h>

t_list		*ft_ls(char **av, int nb, char c)
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
					no_files(av[nb]);
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
