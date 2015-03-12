/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 12:48:04 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/12 11:42:33 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>
#include "libft.h"

int		test_option(char **argv, int i, int j, int *nb)
{
	unsigned int flags;

	flags = 0;
	while (argv[++i] && (*nb = *nb + 1))
	{
		if (argv[i][j] == '-')
			while (argv[i][++j])
			{
				if (argv[i][j] == 'a')
					flags = flags | OPT_A;
				else if (argv[i][j] == 't')
					flags = flags | OPT_T;
				else if (argv[i][j] == 'l')
					flags = flags | OPT_L;
				else if (argv[i][j] == 'r')
					flags = flags | OPT_R;
				else if (argv[i][j] == 'R')
					flags = flags | OPT_R_R;
				else if (argv[i][j] == '-')
					flags = flags | OPT_R_S;
				else
					return (check_option_illegal(argv[i]));
			}
		else
			return (flags);
		j = 0;
	}
	return (flags);
}
