#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>

int		test_open(char *s)
{
  DIR *dirp;

  if ((dirp = opendir(s)) == NULL)
    return (0);
  return (1);
}
