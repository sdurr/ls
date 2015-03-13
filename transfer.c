/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 17:43:22 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/13 17:45:27 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

t_list		*transfer(t_list *s, char *str, char *path, int n)
{
	s->s = ft_strdup(str);
	s->n = n;
	s->path = ft_strdup(path);
	return (s);
}
