/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noms_proprietaire.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 10:28:02 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/12 16:20:09 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>
#include "libft.h"
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>

char 	*name_owner(char *av)
{
	struct passwd *result;
	struct stat sb;
	struct group *group;
	int c;
	char *tmp;
	char *t;

	t = ft_strnew(15);
	lstat(av, &sb);
	result = getpwuid(sb.st_uid);
	tmp = ft_strdup(result -> pw_name);
	tmp = ft_strjoin(tmp, "  ");
	group = getgrgid(sb.st_gid);
	tmp = ft_strjoin(tmp, group -> gr_name);
	c = sb.st_size;
	if (ft_strcmp(group->gr_name, "wheel") == 0)
		tmp = ft_strjoin(tmp, "       ");
	else
	{
	if (c > 999999)
		tmp = ft_strjoin(tmp, " ");
	if (c > 99999 && c < 1000000)
		tmp = ft_strjoin(tmp, " ");
	if (c > 9999 && c < 100000)
		tmp = ft_strjoin(tmp, "  ");
	if (c > 999 && c < 10000)
		tmp = ft_strjoin(tmp, "   ");
	if (c > 99 && c < 1000)
		tmp = ft_strjoin(tmp, "    ");
	if (c > 9 && c < 100)
		tmp = ft_strjoin(tmp, "     ");
	if (c >= 0 && c < 10)
		tmp = ft_strjoin(tmp, "      ");
	}
	if (S_ISCHR(sb.st_mode))
	{
/*utiliser ft_litoa et conter le nombre de chifre, les mettre en puissance...*/
  t = ft_itoa(sb.st_dev);
		tmp = ft_strjoin(tmp, t);
		tmp = ft_strjoin(tmp, ", ");
		tmp = ft_strjoin(tmp, ft_itoa(sb.st_rdev));
	}
	else
	tmp = ft_strjoin(tmp, ft_itoa(sb.st_size));
	return (tmp);
}
