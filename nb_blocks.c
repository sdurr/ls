/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_total_blocks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 13:21:16 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/11 13:59:46 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "libft.h"
#include "ft_ls.h"

void	nb_blocks(t_list *s)
{
	struct stat sb;
	int c;

	c = 0;
	while (s && ft_strchr(s->s, ':'))
	{
		if (stat(s->path, &sb) != -1)
			c = c + sb.st_blocks;
		s = s->next;
	}
	ft_putstr("total ");
	ft_putnbr(c);
	ft_putchar ('\n');

}
