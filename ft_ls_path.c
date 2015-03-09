/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 08:53:06 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/09 10:52:51 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include "libft.h"

t_path		*ft_ls_path(t_list *s, t_path *path)
{
	char *test;
	char *tmp;
	t_list *begin;

	begin = s;
	test = ft_strdup (".");
	if (s->s[1])
		test = ft_strjoin(test, s->s);
	s = s->next;
	if (*test != '\0')
		test = ft_strjoin(test, "/");
	while (s->next != NULL)
	{
		tmp = ft_strdup(test);
		if (s->n == 1)
		{
			tmp = ft_strjoin(test, s->s);
			path = ft_create_elem_path(path, tmp, test_open(tmp));
		}
		s = s->next;
	}
	s = begin;
	return (path);
}
