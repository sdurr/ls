/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 09:47:12 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/27 22:11:53 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_strnew(len);
	if (s)
	{
		if (s[start] || s[len - 1])
		{
			if (!(ret = (char *)malloc(sizeof(char*) * len + 1)))
				return (NULL);
			while (len != 0)
			{
				ret[i] = s[start];
				start++;
				len--;
				i++;
			}
		}
	}
	else
		return (NULL);
	ret[i] = '\0';
	return (ret);
}
