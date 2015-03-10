/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 08:53:06 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/10 14:41:32 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include "libft.h"

char		*ft_ls_path(char *file, char *name)
{
	char *ret;

	ret = ft_strjoin(file, "/");
	ret = ft_strjoin(ret, name);
	return (ret);
}
