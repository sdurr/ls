/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_perm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 09:32:12 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/12 11:41:24 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>
#include <errno.h>
#include "libft.h"

int			test_perm(char *s)
{
	struct stat sb;

	stat(s, &sb);
	if (sb.st_mode & S_IROTH)
		return (1);
	else
	{
		ft_putstr_fd("./ft_ls: ", 2);
		s++;
		s++;
		ft_putstr_fd(s, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		return (0);
	}
}
