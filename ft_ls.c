/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 17:41:36 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/09 14:44:21 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdio.h>

t_list		*ft_ls(char **av, int nb, char c)
{
	t_list *s;
	t_path *path;

	if (av)
	path = malloc(sizeof(t_path));
	path = NULL;
	s = malloc(sizeof(t_list));
	s = NULL;
	nb++;
	if (!(av[nb]))
		s = ft_ls_read(".", s, c);
	else
	{
		av[nb] = ft_strjoin("./", av[nb]);
		while (av[nb])
			s = ft_ls_read(av[nb++], s, c);
	}
		return (s);
}
