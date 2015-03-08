/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 22:00:17 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/27 22:12:18 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char *ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_strnew(15);
	if (s && f)
	{
		if (!(ret = (char *)malloc(sizeof(char*) * ft_strlen(s))))
			return (NULL);
		while (s[i] != '\0')
		{
			ret[i] = f(s[i]);
			i++;
		}
	}
	return (ret);
}
