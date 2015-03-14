/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list_opt_r.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 12:57:22 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/14 14:14:32 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

t_list		*print_dir(t_list *s)
{
	if (ft_strcmp(s->s, ". :") != 0)
	{
		ft_putchar ('\n');
		ft_putendl(s->s);
	}
	if (s->next != NULL)
	{
		nb_blocks(s);
		s = s->next;
	}
	return (s);
}

t_list		*print_first_link(t_list *s)
{
	if (ft_strcmp(s->s, ". :") == 0)
	{
		nb_blocks(s);
		s = s->next;
		while (s->n != 2 && s->next != NULL)
			s = s->next;
		s = s->prev;
		while (s->n != 2 && s->prev != NULL)
		{
			ft_putendl(s->s);
			s = s->prev;
		}
		s = s->next;
		while (s->n != 2 && s->next != NULL)
			s = s->next;
		s->prev = NULL;
	}
	return (s);
}

int			print_list_opt_r(t_list *s)
{
	s = print_first_link(s);
	while (s)
	{
		while (s->next != NULL)
			s = s->next;
		while (s->n != 2 && s->prev != NULL)
			s = s->prev;
		if (s->n == 2 && s->next != NULL)
			s = print_dir(s);
		while (s->n != 2 && s->next != NULL)
			s = s->next;
		while (s->n != 2 && s->prev != NULL)
		{
			ft_putendl(s->s);
			s = s->prev;
		}
		if (s->prev != NULL)
			s = s->prev;
		if (s->next == NULL)
			return (0);
		s->next = NULL;
	}
	return (0);
}