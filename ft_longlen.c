/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlen.c                                       :+:      :+:    :+:   */

/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 16:18:05 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/13 09:16:43 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

long long		ft_longlen(long long l)
{
	long long	ret;

	ret = 1;
	if (l < 0)
	{
		if (l < LONG_LONG_MIN)
			return (12);
		ret++;
		l *= -1;
	}
	while ((l /= 10) > 0)
		ret++;
	return (ret);
}
