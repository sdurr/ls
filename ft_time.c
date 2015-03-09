/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 11:19:23 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/09 10:12:15 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <sys/stat.h>
#include "ft_ls.h"
#include "libft.h"

char 	*ft_time(char *av)
{
	struct	stat sb;
	time_t time;
	char *ret;
	int i;
	char *tmp;
	int j;

	tmp = ft_strnew(17);
	i = 4;
	j = 0;
	stat(av, &sb);
	time = sb.st_mtime;
	ret =ctime(&time);
	while (i < 16)
		tmp[j++] = ret[i++];
	tmp = ft_strjoin(tmp, " ");
return (tmp);
}
