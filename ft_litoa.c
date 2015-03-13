/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 17:11:27 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/13 09:04:30 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ls.h"
#include "limits.h"

char	*ft_litoa(long long n)
{
	char	*ret;
	int		i;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * ft_longlen(n) + 1)))
		return (NULL);
	if (n < 0)
	{
		ret[i++] = '-';
		n *= -1;
	}
	while (n >= 10 && n <= LONG_LONG_MAX)
	{
		ret[i++] = n % 10 + '0';
		n = n / 10;
	}
	if (n < 10)
		ret[i++] = n + '0';
	ret[i] = '\0';
	ret = ft_revers(ret);
	return (ret);
}
