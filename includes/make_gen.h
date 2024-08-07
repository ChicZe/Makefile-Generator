#ifndef MAKE_GEN_H
# define MAKE_GEN_H

# include <stdio.h>
# include <dirent.h>
# include <fcntl.h>
# include "defines.h"
# include "structs.h"
# include "../libft/libft.h"

extern int 	error_status;
extern char	**all_flag;

/**----------------------
 *?    INITIALIZATION
 *------------------------**/
int		init_all(t_make *make);
char	*get_name(void);
char	*get_src(void);

/**======================
 *?    		UTILS
 *========================**/
char	*format_src(char *src);
char	*get_cmd_output(char *cmd);
char	*var_declaration(char *name);

/**----------------------
 *?    COMPOSING MAKEFILE
 *------------------------**/
int		create_file(t_make *make);
int		write_makefile(t_make *make);

/**----------------------
 *?    	  ERROR
 *------------------------**/
int		error(char *err_type);

/**----------------------
 *?    	   PARSING
 *------------------------**/
int	parse_flags(t_make *make, int argc, char **argv);
int	flags_manager(t_make *make, char *flag, int type);
int	setup_basic_rules(t_make *make);

/**----------------------
 *?    	  MESSAGES
 *------------------------**/
void	welcome_msg(void);
void	usage(void);

/**=======================
 *?    	  	EXIT
 *========================**/
void	quit(t_make *make);

#endif