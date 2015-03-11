/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:35:51 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/11 17:16:33 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>
#include <sys/stat.h>

t_list 	*opt_l(t_list *s)
{
	struct stat			sb;
	int			c;
	char		*buf;
	t_list *begin;
	char *link;

	begin = s;
	c = 0;
	buf = ft_strnew(15);
	while (s)
	{
		if (ft_strchr(s->s, ':') != NULL)
		{
							s = s->next;
		}
			if ((stat(s->path, &sb)) == -1)
			s = s->next;
		buf = ft_strdup(ft_permission(s->path));
		c = ft_count_sous_dossiers(s->path);
		if (c < 10)
			buf = ft_strjoin(buf, "    ");
		else if (c < 99 && c > 9)
			buf = ft_strjoin(buf, "   ");
		else if (c < 999 && c > 99)
			buf = ft_strjoin(buf, "  ");
		else
			buf = ft_strjoin(buf, " ");
		buf = ft_strjoin(buf, ft_itoa(c));
		buf = ft_strjoin(buf, opt_uid_time(s->path));
		if (lstat(s->s, &sb) != -1)
			link = ft_strdup(s->s);
		s->s = ft_strjoin(buf, s->s);
		if (S_ISLNK(sb.st_mode))
		{
			buf  = ft_strnew(50);
			s->s = ft_strjoin(s->s, " -> ");
			readlink(link, buf, 50);
			s->s = ft_strjoin(s->s, buf);
		}
		s = s->next;
	}
	return (begin);
}
