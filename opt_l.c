/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:35:51 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/15 10:09:57 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>
#include <sys/stat.h>

static char		*join_subfolder(int c, char *buf)
{
	if (c < 10)
		buf = ft_strjoin(buf, "   ");
	else if (c < 99 && c > 9)
		buf = ft_strjoin(buf, "  ");
	else if (c < 999 && c > 99)
		buf = ft_strjoin(buf, " ");
	else
		buf = ft_strjoin(buf, "");
	return (buf);
}

static char		*link_read(char *link)
{
	char *buf;

	buf = ft_strnew(15);
	readlink(link, buf, 50);
	buf = ft_strjoin(" -> ", buf);
	return (buf);
}

t_list			*opt_l(t_list *s)
{
	struct stat			sb;
	int					c;
	char				*buf;
	t_list				*begin;

	begin = s;
	while (s)
	{
		while (s->n == 2)
			s = s->next;
		lstat(s->path, &sb);
		buf = ft_strdup(ft_permission(s->path));
		c = ft_count_sous_dossiers(s->path);
		buf = join_subfolder(c, buf);
		buf = ft_strjoin(buf, ft_strjoin(ft_itoa(c), opt_uid_time(s->path)));
		s->s = ft_strjoin(buf, s->s);
		buf = ft_strdup(s->path);
		if (S_ISLNK(sb.st_mode))
		{
			s->n = 0;
			s->s = ft_strjoin(s->s, link_read(buf));
		}
		s = s->next;
	}
	return (begin);
}
