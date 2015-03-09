/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 08:49:35 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/09 17:27:41 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

t_list		*ret_ls(t_list *s, char **av, int flags, int nb)
{
	if (flags & OPT_A)
		s = ft_ls(av, nb, 125);
	else
		s = ft_ls(av, nb, '.');
	//if (flags & OPT_R_R)
	if (flags & OPT_T)
		s = opt_t(s);
	if (flags & OPT_L)
		s = opt_l(s);
	return (s);
}
