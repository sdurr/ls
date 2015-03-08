/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 11:03:53 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/03 11:41:10 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list*))
{
	t_list	*ret;
	t_list	*tmp;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	if ((ret = ft_lstnew(new->content, new->content_size)))
	{
		tmp = ret;
		lst = lst->next;
		while (lst)
		{
			new = f(lst);
			if (!(tmp->next = ft_lstnew(new->content, new->content_size)))
				return (NULL);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (ret);
}
