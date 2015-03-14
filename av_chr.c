/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_chr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 14:52:48 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/14 17:10:22 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

char		*av_chr3(char *t, struct stat s)
{
	if (S_ISCHR(s.st_mode))
		t = ft_strjoin(t, "       ");
	else
		t = ft_strjoin(t, "         ");
	return (t);
}

char		*av_chr2(char *t, struct stat s, struct group *g)
{
	if (ft_strlen(g->gr_name) == 8)
	{
		if (!(S_ISCHR(s.st_mode)))
			t = ft_strjoin(t, "  ");
		else
			t = ft_strjoin(t, "  ");
	}
	else if (ft_strlen(g->gr_name) >= 4)
	{
		if (S_ISCHR(s.st_mode))
			t = ft_strjoin(t, "     ");
		else if (!(S_ISDIR(s.st_mode)))
			t = ft_strjoin(t, "       ");
		else
			t = ft_strjoin(t, "  ");
	}
	else if (ft_strlen(g->gr_name) <= 3)
		t = av_chr3(t, s);
	return (t);
}

char		*av_chr(char *t, struct stat s, struct group *g, struct passwd *r)
{
	if (ft_strlen(r->pw_name) > 4 && ft_strlen (r->pw_name) < 8)
		t = ft_strjoin(t, "  ");
	else if (ft_strlen (r->pw_name) < 8)
		t = ft_strjoin(t, "   ");
	t = ft_strjoin(t, g->gr_name);
	if (!(S_ISCHR(s.st_mode)))
		t = ft_strjoin(t, " ");
	t = ft_strdup(av_chr2(t, s, g));
	if (S_ISBLK(s.st_mode))
		t = ft_strjoin(t, "    ");
	if (S_ISLNK(s.st_mode))
		t = ft_strjoin(t, "  ");
	return (t);
}
