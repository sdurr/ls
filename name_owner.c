/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noms_proprietaire.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 10:28:02 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/16 13:23:19 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>
#include "libft.h"
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>

static char			*join_size(char *tmp, int c)
{
	tmp = ft_strjoin(tmp, "  ");
	if (c > 999999)
		tmp = ft_strjoin(tmp, "");
	if (c > 99999 && c < 1000000)
		tmp = ft_strjoin(tmp, "");
	if (c > 9999 && c < 100000)
		tmp = ft_strjoin(tmp, " ");
	if (c > 999 && c < 10000)
		tmp = ft_strjoin(tmp, "  ");
	if (c > 99 && c < 1000)
		tmp = ft_strjoin(tmp, "   ");
	if (c > 9 && c < 100)
		tmp = ft_strjoin(tmp, "    ");
	if (c >= 0 && c < 10)
		tmp = ft_strjoin(tmp, "     ");
	return (tmp);
}

static char			*chr(struct stat sb, char *tmp)
{
	if (major(sb.st_rdev) < 10)
		tmp = ft_strjoin(tmp, "  ");
	else if (major(sb.st_rdev) < 100)
		tmp = ft_strjoin(tmp, " ");
	tmp = ft_strjoin(tmp, ft_itoa(major(sb.st_rdev)));
	tmp = ft_strjoin(tmp, ",");
	if (minor(sb.st_rdev) < 10)
		tmp = ft_strjoin(tmp, "   ");
	else if (minor(sb.st_rdev) < 100)
		tmp = ft_strjoin(tmp, "  ");
	else
		tmp = ft_strjoin(tmp, " ");
	tmp = ft_strjoin(tmp, ft_itoa(minor(sb.st_rdev)));
	return (tmp);
}

char				*name_owner(char *av)
{
	char			*tmp;
	struct passwd	*result;
	struct group	*group;
	struct stat		sb;

	lstat(av, &sb);
	result = getpwuid(sb.st_uid);
	tmp = ft_strdup(result->pw_name);
	group = getgrgid(sb.st_gid);
	if (av[0] == '/')
		tmp = ft_strdup(av_chr(tmp, sb, group));
	tmp = ft_strjoin(tmp, "  ");
	if (av[0] != '/')
		tmp = ft_strjoin(tmp, group->gr_name);
	if (av[0] != '/' || (av[0] == '/' && S_ISDIR(sb.st_mode)))
		tmp = ft_strdup(join_size(tmp, sb.st_size));
	if (S_ISCHR(sb.st_mode))
		tmp = ft_strdup(chr(sb, tmp));
	else
	{
		if (av[0] == '/')
			tmp = ft_strjoin(tmp, "  ");
		tmp = ft_strjoin(tmp, ft_itoa(sb.st_size));
	}
	return (tmp);
}
