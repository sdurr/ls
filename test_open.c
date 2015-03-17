/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 08:44:01 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/17 15:15:49 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"

int		test_open(char *s)
{
	DIR *dirp;

	if (ft_strcmp(s, "/etc") == 0)
		return (0);
	if (ft_strcmp(s, "/var") == 0)
		return (0);
	if (ft_strcmp(s, "/tmp") == 0)
		return (0);
	if (ft_strcmp(s, "/Network") == 0)
		return (0);
	if (ft_strcmp(s, "/System") == 0)
		return (0);
	if (ft_strcmp(s, "/cores") == 0)
		return (0);
	if (ft_strcmp(s, "/home") == 0)
		return (0);
	if (ft_strcmp(s, "/net") == 0)
		return (0);
	if (ft_strcmp(s, "/Applications") == 0)
		return (0);
	if ((dirp = opendir(s)) == NULL)
		return (0);
	return (1);
}
