/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 17:41:36 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/11 14:26:48 by sdurr            ###   ########.fr       */
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
	nb++;
	if (!(av[nb]))
		s = ft_ls_read(".", s, c);
	else
	{
		if (av[nb][0] != '/')
			av[nb] = ft_strjoin("./", av[nb]);
		while (av[nb])
			s = ft_ls_read(av[nb++], s, c);
	}
	ft_putstr(s->s);
	return (s);
}
