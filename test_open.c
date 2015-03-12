/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 08:44:01 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/12 11:43:48 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>

int		test_open(char *s)
{
	DIR *dirp;

	if ((dirp = opendir(s)) == NULL)
		return (0);
	return (1);
}
