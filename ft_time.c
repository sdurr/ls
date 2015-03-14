/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 11:19:23 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/14 15:44:16 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <sys/stat.h>
#include "ft_ls.h"
#include "libft.h"

char		*ft_time(char *av)
{
	struct stat sb;
	time_t		time;
	char		*ret;
	int			i[2];
	char		*tmp;

	tmp = ft_strnew(17);
	i[0] = 4;
	i[1] = 0;
	stat(av, &sb);
	time = sb.st_mtime;
	ret = ctime(&time);
	while (i[0] < 16)
		tmp[i[1]++] = ret[i[0]++];
	tmp = ft_strjoin(tmp, " ");
	return (tmp);
}
