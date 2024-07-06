#ifndef MAKE_GEN_H
# define MAKE_GEN_H
	
# include <stdio.h>
# include <dirent.h>
# include <fcntl.h>
# include "defines.h"
# include "structs.h"
# include "../libft/libft.h"

/**----------------------
 *?    INITIALIZATION
 *------------------------**/

int		init_all(t_make *make);

/**----------------------
 *?    COMPOSING MAKEFILE
 *------------------------**/
int		create_file(t_make *make);

/**----------------------
 *?    	  ERROR
 *------------------------**/
int		error(int err_type);

#endif