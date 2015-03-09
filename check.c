/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 13:26:20 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/09 13:31:03 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			check(char **av)
{
	int i;
	int j;

	j = 0;
	i = 1;
	while (av[i])
	{
		while (av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == 't' || av[i][j] == 'l'
				|| av[i][j] == 'a' || av[i][j] == 'r' || av[i][j] == 'R')
				j++;
			if (av[i][j] == ' ')
				i++;
			i++;
		}
}
