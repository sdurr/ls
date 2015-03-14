/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_l_uid_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 18:11:31 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/14 17:01:23 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

char		*opt_uid_time(char *tab)
{
	char *tmp;

	tmp = ft_strdup(" ");
	tmp = ft_strjoin(tmp, name_owner(tab));
	tmp = ft_strjoin(tmp, " ");
	tmp = ft_strjoin(tmp, ft_time(tab));
	return (tmp);
}
