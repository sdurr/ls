/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_total_blocks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 13:21:16 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/09 17:34:12 by sdurr            ###   ########.fr       */
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
	while (ft_strchr(s->s, ':') != NULL)
		s = s->next;
	while (s->next != NULL)
	{
		stat(s->s, &sb);
		c = c + sb.st_blocks;
		s = s->next;
		ft_putstr("seg");
	}
	ft_putstr("total ");
	ft_putnbr(c);
	ft_putchar ('\n');

}
