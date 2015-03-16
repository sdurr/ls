/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:33:10 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/15 10:40:36 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define OPT_L		4
# define OPT_A		8
# define OPT_T		16
# define OPT_R		32
# define OPT_R_R	64
# define OPT_R_S	128

# include <string.h>
# include <pwd.h>
# include <grp.h>
# include <sys/stat.h>

typedef struct		s_list
{
	struct s_list	*prev;
	char			*s;
	char			*path;
	int				n;
	struct s_list	*next;
}					t_list;

typedef struct		s_ascii
{
	char			*tmp;
	char			*path;
	int				tmp_n;
}					t_ascii;

typedef struct		s_time
{
	int				first;
	int				second;
}					t_time;

t_list				*ft_create_elem(t_list *t, char *s, char *path, int n);
t_list				*ret_ls(t_list *s, char **av, int flags, int nb);
t_list				*opt_t(t_list *s);
t_list				*ft_ls(char **av, int nb, char c);
t_list				*opt_l(t_list *s);
t_list				*tri_ascii(t_list *s);
t_list				*tri_ascii_path(t_list *s);
t_list				*open_list(t_list *s, char c);
t_list				*exchange_link(t_list *s, t_list *t);
t_list				*transfer(t_list *s, char *str, char *path, int n);
t_list				*ft_ls_read(char *av, t_list *s, char c);

char				*ft_ls_path(char *file, char *name);
char				*av_chr(char *t, struct stat s, struct group *g, struct passwd *r);
char				*ft_permission(char *tab);
char				*name_owner(char *av);
char				*ft_time(char *av);
char				*opt_uid_time(char *tab);
char				*test_files(char *argv);

int					test_dir(t_list *s);
int					check_option_illegal(char *argv);
int					test_open(char *s);
int					test_perm(char *s);
int					test_option(char **argv, int i, int j, int *nb);
int					print_list_opt_r(t_list *s, char **av, int nb);
int					print_list(t_list *s);
int					ft_count_sous_dossiers(char *tab);

void				no_files(char *s);
void				nb_blocks(t_list *s);

#endif
