/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_files_or_directory.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 15:42:54 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/16 15:49:13 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void		no_files(char *s)
{
	ft_putstr_fd("ft_ls: ", 2);
	if (ft_strncmp(s, "./", 2) == 0)
		s += 2;
	ft_putstr_fd(s, 2);
	ft_putstr_fd(":", 2);
	ft_putstr_fd(" No such file or directory\n", 2);
}
