/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 10:39:21 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/29 22:19:13 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include "libft.h"

int		check_option_illegal(char *argv)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(argv[1], 2);
	ft_putstr_fd("\nusage: ls [-ABCFGHLOPRSTUWabcdefghijklmnopqrstuwx1]", 2);
	ft_putstr_fd("[file ...]", 2);
	ft_putchar_fd ('\n', 2);
	return (-1);
}
