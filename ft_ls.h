/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:33:10 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/05 18:00:47 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_LS_H
# define	FT_LS_H

# define OPT_L 4
# define OPT_A 8
# define OPT_T 16
# define OPT_R 32
# define OPT_R_R 64
# define OPT_R_S 128

typedef struct	s_list
{
	struct	s_list	*prev;
			char	*s;
			int		n;
	struct	s_list	*next;
}				t_list;

typedef struct	s_path
{
	struct	s_path	*prev;
			char	*s;
			int		n;
	struct	s_path	*next;
}				t_path;

t_list		*ft_create_elem(t_list *t, char *s, int n);
t_list		*ft_ls_read(char *av, t_list *s);

t_path		*ft_create_elem_path(t_path *t, char *s, int n);
t_path		*ft_ls_path(t_list *s, t_path *path);
int		test_open(char *s);
#endif
