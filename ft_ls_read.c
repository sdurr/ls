/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 08:45:54 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/17 10:32:54 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <dirent.h>
#include "ft_ls.h"
#include <stdlib.h>

t_list		*ft_ls_read(char *av, t_list *s, char c)
{
	DIR				*dirp;
	struct dirent	*read;
	char			*t;
	char			*path;
	int				d;

	t = ft_strnew(15);
	t = ft_strdup(av);
	s = ft_create_elem(s, ft_strjoin(av, " :"), ft_ls_path(t, ""), 2);
	if ((dirp = opendir(t)) != NULL)
	{
		while ((read = readdir(dirp)) != NULL)
			if (read->d_name[0] != c)
			{
				path = ft_ls_path(t, read->d_name);
				d = test_open(ft_ls_path(t, read->d_name));
				s = ft_create_elem(s, ft_strdup(read->d_name), path, d);
			}
	}
	else
	{
		path = ft_strjoin("./", t);
		s = ft_create_elem(s, ft_strdup(av), path, 0);
	}
	return (s);
}
