/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 09:29:47 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/16 15:18:59 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>

char		*test_files(char *argv)
{
	DIR				*dirp;
	struct dirent	*read;

	argv += 2;
	if ((dirp = opendir(".")) != NULL)
		while ((read = readdir(dirp)) != NULL)
			if ((ft_strcmp(argv, read->d_name)) == 0)
				return (argv);
	return (NULL);
}
