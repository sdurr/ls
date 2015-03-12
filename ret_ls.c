/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 08:49:35 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/12 08:55:25 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

t_list		*ret_ls(t_list *s, char **av, int flags, int nb)
{
	char c;

	if (flags & OPT_A)
	{
		c = 125;
		s = ft_ls(av, nb, 125);
	}
	else
	{
		c = '.';
		s = ft_ls(av, nb, '.');
	}
	s = tri_ascii(s);
	if (flags & OPT_R_R)
		while (test_dir(s) == 1)
			s = open_list(s, c);
	if (flags & OPT_T)
		s = opt_t(s);
	if (flags & OPT_L)
		s = opt_l(s);
	return (s);
}
