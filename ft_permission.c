/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 13:08:07 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/14 15:42:11 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>
#include <sys/stat.h>

char		*perm_2(char *tmp, struct stat sb)
{
	if (sb.st_mode & S_IXGRP)
		tmp = ft_strjoin(tmp, "x");
	else
		tmp = ft_strjoin(tmp, "-");
	if (sb.st_mode & S_IROTH)
		tmp = ft_strjoin(tmp, "r");
	else
		tmp = ft_strjoin(tmp, "-");
	if (sb.st_mode & S_IWOTH)
		tmp = ft_strjoin(tmp, "w");
	else
		tmp = ft_strjoin(tmp, "-");
	if (sb.st_mode & S_IXOTH)
		tmp = ft_strjoin(tmp, "x");
	else
		tmp = ft_strjoin(tmp, "-");
	return (tmp);
}

char		*perm(char *tmp, struct stat sb)
{
	if (sb.st_mode & S_IRUSR)
		tmp = ft_strjoin(tmp, "r");
	else
		tmp = ft_strjoin(tmp, "-");
	if (sb.st_mode & S_IWUSR)
		tmp = ft_strjoin(tmp, "w");
	else
		tmp = ft_strjoin(tmp, "-");
	if (sb.st_mode & S_IXUSR)
		tmp = ft_strjoin(tmp, "x");
	else
		tmp = ft_strjoin(tmp, "-");
	if (sb.st_mode & S_IRGRP)
		tmp = ft_strjoin(tmp, "r");
	else
		tmp = ft_strjoin(tmp, "-");
	if (sb.st_mode & S_IWGRP)
		tmp = ft_strjoin(tmp, "w");
	else
		tmp = ft_strjoin(tmp, "-");
	return (perm_2(tmp, sb));
}

char		*ft_permission(char *tab)
{
	struct stat	sb;
	char		*tmp;

	lstat(tab, &sb);
	if (S_ISREG(sb.st_mode))
		tmp = ft_strdup("-");
	if (S_ISLNK(sb.st_mode))
		tmp = ft_strdup("l");
	if (S_ISDIR(sb.st_mode))
		tmp = ft_strdup("d");
	if (S_ISBLK(sb.st_mode))
		tmp = ft_strdup("b");
	if (S_ISCHR(sb.st_mode))
		tmp = ft_strdup("c");
	if (S_ISFIFO(sb.st_mode))
		tmp = ft_strdup("|");
	tmp = perm(tmp, sb);
	return (tmp);
}
