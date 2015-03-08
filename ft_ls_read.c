
#include "libft.h"
#include <dirent.h>
#include "ft_ls.h"
#include <stdlib.h>

t_list		*ft_ls_read(char *av, t_list *s)
{
  DIR *dirp;
  struct dirent *read;
  char *t;
  char *d;

  if (av)
    t = ft_strdup(av);
  else
    t = ft_strdup(".");
  s = ft_create_elem(s, t, 10);
  if ((dirp = opendir(t)) != NULL)
    {
      while ((read = readdir(dirp)) != NULL)
	{
	  if (read->d_name[0] != '.')
	    {
	      if (t)
		{
		  d = ft_strdup(t);
		  d = ft_strjoin(d, "/");
		  d = ft_strjoin(d, read->d_name);
		}		 
 s = ft_create_elem(s, read->d_name, test_open(d));
	    }
	}
    } 
  return (s);
}

