/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:23:27 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/27 22:11:02 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*ret;
	const char	*srcs;
	int			i;

	i = 0;
	ret = ft_strnew(ft_strlen(dst));
	if (dst || src)
	{
		ret = dst;
		srcs = src;
		while (n != 0)
		{
			ret[i] = srcs[i];
			i++;
			n--;
		}
	}
	return (ret);
}
