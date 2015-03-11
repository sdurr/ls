
#include "libft.h"
#include <dirent.h>
#include "ft_ls.h"
#include <stdlib.h>

t_list		*ft_ls_read(char *av, t_list *s, char c)
{
  DIR *dirp;
  struct dirent *read;
  char *t;

  t = ft_strnew(15);
  if (av)
    t = ft_strdup(av);
  s = ft_create_elem(s, t, ft_ls_path(t, ""), 2);
  if ((dirp = opendir(t)) != NULL)
  {
      while ((read = readdir(dirp)) != NULL)
	  {
		  if (read->d_name[0] != c)
		  {
/*			  ft_putstr(" test open path = ");
			  ft_putendl(ft_ls_path(t, read->d_name));
			  ft_putnbr(test_open(ft_ls_path(t, read->d_name)));
			  ft_putchar ('\n');
			  ft_putchar ('\n');
*/		  s = ft_create_elem(s, ft_strdup(read->d_name), ft_ls_path(t, read->d_name), test_open(ft_ls_path(t, read->d_name)));


		  }
	  }
  }
  return (s);
}

