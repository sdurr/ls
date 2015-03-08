/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 17:41:36 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/05 18:18:35 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_list *s;
	t_path *path;

       path = malloc(sizeof(t_path));
       path = NULL;	
       s = malloc(sizeof(t_list));
	s = NULL;	
	if (ac > 0)
	s = ft_ls_read(av[1], s);  
	path = ft_ls_path(s, path);
	s=s->next;
	while (path->next != NULL)
	  {
		if (path->n == 1)
		  {
		    path->n = 0;
		    s = ft_ls_read(path->s, s);
		    path = ft_ls_path(s, path);
		  }	
		path = path->next;
	  }
	if (path->n == 1)
	  {
	    s = ft_ls_read(path->s, s);
		    path = ft_ls_path(s, path);
	  }
	
	while (s->next != NULL)	    
	      {
		//		ft_putstr(s->s);
		//ft_putnbr(s->n);
		//ft_putchar ('\n');
		//s = s->next;
		}
	return (0);
}
