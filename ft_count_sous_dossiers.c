/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_sous_dossiers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 14:09:12 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/19 17:54:23 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>

int		ft_count_sous_dossiers(char *tab)
{
	int				i;
	DIR				*dirp;
	struct dirent	*read;

	i = 0;
	if ((dirp = opendir(tab)) != NULL)
	{
		while ((read = readdir(dirp)) != NULL)
			i++;
	}
	if (i > 0)
		return (i);
	else
		return (1);
	return (0);
}
