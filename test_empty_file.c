/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_empty_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 15:33:25 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/17 15:39:05 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

t_list	*test_empty_file(t_list *s)
{
	t_list *begin;

	begin = s;
	while (s->next != NULL)
		s = s->next;
	if (s->n == 2)
	{
		s = ft_create_elem(s, ft_strdup(""), ft_strdup(""), -4);
	}
	return (begin);
}
